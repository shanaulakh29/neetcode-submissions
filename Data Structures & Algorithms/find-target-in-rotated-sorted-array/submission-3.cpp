class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;                          // left boundary
        int r = nums.size() - 1;            // right boundary
        
        while (l <= r) {                    // standard binary search loop
            int mid = l + (r - l) / 2;      // avoid overflow when computing mid
            
            if (target == nums[mid]) {      // if target is found at mid
                return mid;
            }
            
            // Case 1: Left half [l..mid] is sorted
            if (nums[mid] >= nums[l]) {
                
                // If target is outside the sorted left half, search right
                if (target < nums[l] || target > nums[mid]) {
                    l = mid + 1;
                } 
                // Otherwise, target is inside the sorted left half
                else if (target >= nums[l] && target < nums[mid]) {
                    r = mid - 1;
                }
            } 
            // Case 2: Right half [mid..r] is sorted
            else {
                
                // If target is outside the sorted right half, search left
                if (target > nums[r] || target < nums[mid]) {
                    r = mid - 1;
                } 
                // Otherwise, target is inside the sorted right half
                else if (target > nums[mid]) {
                    l = mid + 1;
                }
            }
        }
        
        // If we exit loop, target was not found
        return -1;
    }
};

//Another ans from gpt but use the first one to get a good picture of the question:
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int l = 0, r = nums.size() - 1;

//         while (l <= r) {
//             int mid = l + (r - l) / 2;

//             if (nums[mid] == target) {
//                 return mid;  // return immediately when found
//             }

//             // Left half is sorted
//             if (nums[mid] >= nums[l]) {
//                 if (target >= nums[l] && target < nums[mid]) {
//                     r = mid - 1;  // target in left half
//                 } else {
//                     l = mid + 1;  // target in right half
//                 }
//             } 
//             // Right half is sorted
//             else {
//                 if (target > nums[mid] && target <= nums[r]) {
//                     l = mid + 1;  // target in right half
//                 } else {
//                     r = mid - 1;  // target in left half
//                 }
//             }
//         }

//         return -1; // not found
//     }
// };
