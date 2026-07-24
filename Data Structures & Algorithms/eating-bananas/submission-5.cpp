class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxValue=0;
        for(int i=0;i<piles.size();i++){
            maxValue=max(maxValue, piles[i]);//O(n)
        }
        int left=1;
        int right=maxValue;
        int eatingSpeed;
        int minSpeed=INT_MAX;
        //O(nlog(m))
        while(left<=right){//O(log(m))
            eatingSpeed = left+(right-left)/2;
            int hour=0;
            for(int i=0;i<piles.size();i++){//O(n)
                hour+=ceil((double)piles[i]/eatingSpeed);
            }

            if(hour<=h){
                minSpeed = min(minSpeed, eatingSpeed);
                right=eatingSpeed-1;
            }else{
                left=eatingSpeed+1;
            }
        }
        return minSpeed;
    }
};
//1,2,3,4
