class Solution {
public:
    int getTotalHours(int speed, vector<int>&piles, int h){
        int hours = 0;
        for(int pile:piles){
            hours+=ceil((double)pile/speed);
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int minspeed=1;
        int maxspeed =0;
        for(int pile:piles){
            maxspeed = max(pile, maxspeed);
        }
        while(minspeed<=maxspeed){
            int midspeed = minspeed+(maxspeed-minspeed)/2;
           int hours = getTotalHours(midspeed, piles,h);
           if(hours > h){
            minspeed = midspeed+1;
           }else if(hours <= h){
            maxspeed = midspeed-1;
           }
        }
        return minspeed;
    }
};
