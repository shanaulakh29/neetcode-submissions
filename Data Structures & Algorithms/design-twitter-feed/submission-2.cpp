//post tweets
//follow/unfollow
//10 most recent tweets
//uid, tid
//follower follows the followee
class Twitter {
    int time=0;
    unordered_map<int, unordered_set<int>>followMap;
    //posts[userId]->[{time1,tweetId1}, {time2,tweetId2}]
    unordered_map<int, vector<pair<int, int>>>posts;
    
public:
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back(pair<int,int>{time, tweetId});
        time+=1;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int,int,int,int>>maxHeap;
        vector<int>res;
        followMap[userId].insert(userId);//O(1)
        unordered_set<int>&friends = followMap[userId];
        for(const int& followee:friends){
            vector<pair<int,int>>&friendPosts = posts[followee];
            // for(pair<int,int>&friendPost:friendPosts){
            //     maxHeap.push(friendPost);
            // }
            if(friendPosts.size()){
                int index = friendPosts.size()-1;
                pair<int,int>&friendPost = friendPosts[index];
                maxHeap.push({friendPost.first,friendPost.second,followee,index- 1});
            }
        }
        while(!maxHeap.empty()&& res.size()<10){
            auto [time, tweetId, followee, index] = maxHeap.top();
            res.push_back(tweetId);
            maxHeap.pop();
            if(index>=0){
               maxHeap.push({
                posts[followee][index].first,
                posts[followee][index].second,
                followee,
                index-1
               }
               );
            }
        }      
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId); //O(1)
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followMap[followerId].contains(followeeId)){
            followMap[followerId].erase(followeeId); //O(1)
        }   
    }
};
/*
        for(const int& followee:friends){
            vector<pair<int,int>>&friendPosts = posts[followee];
            for(pair<int,int>&friendPost:friendPosts){
                maxHeap.push(friendPost);
            }
        }
*/