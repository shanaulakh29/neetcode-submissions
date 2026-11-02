class Solution {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer>set = new HashSet<>();
        for(int i=0;i<nums.length;i++){//O(n)
            set.add(nums[i]); 
        }
        int maxLength=0;
        for(int i=0;i<nums.length;i++){
            if(set.contains(nums[i]-1))//O(1)
            {
                continue;
            }
            int value = nums[i];
            int length=0;
            while(set.contains(value)){
                length+=1;
                value+=1;
            }
            maxLength = Math.max(maxLength, length);
        }
        return maxLength;
    }
}
