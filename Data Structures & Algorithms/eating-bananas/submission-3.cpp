class Solution {
public:
    int getHours(vector<int>&piles, int h, int speed){
        int hours=0;
        for(int i=0;i<piles.size();i++){
            hours+=ceil((double)piles[i]/speed);
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int minSpeed=1;
        int maxSpeed=0;
        for(int i=0;i<piles.size();i++){
            maxSpeed = max(piles[i], maxSpeed);
        }
        while(minSpeed<=maxSpeed){
            int mid = minSpeed+(maxSpeed-minSpeed)/2;
            int hoursToEat = getHours(piles, h, mid);
            if(hoursToEat>h){
                minSpeed=mid+1;
            }else if(hoursToEat<=h){
                maxSpeed=mid-1;
            }
        }
        return minSpeed;

    }
};
