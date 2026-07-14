class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //[1,2,3,4,5,7,8,9,10] target: 7
        int i=0; //fixed always take 4 bytes
        int j=numbers.size()-1; //fixed always take 4 bytes
        while(i<j){
            int sum=numbers[i]+numbers[j];
            if(sum<target){
                i++;
            }else if(sum>target){
                j--;
            }else{
                break;
            }
        }
        return vector<int>{i+1,j+1};//fixed always takes 2 element space
        //total space taken by algorithm os O(1) and time complexity is O(n)
    }
};
