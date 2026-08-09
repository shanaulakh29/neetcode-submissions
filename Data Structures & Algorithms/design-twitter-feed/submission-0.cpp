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
        priority_queue<pair<int,int>>maxHeap;
        vector<int>res;
        followMap[userId].insert(userId);
        unordered_set<int>&friends = followMap[userId];
        for(const int& followee:friends){
            vector<pair<int,int>>&friendPosts = posts[followee];
            for(pair<int,int>&friendPost:friendPosts){
                maxHeap.push(friendPost);
            }
        }
        while(!maxHeap.empty()&& res.size()<10){
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
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
