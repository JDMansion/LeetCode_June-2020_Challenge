// Single Element in a Sorted Array   ( Leetcode )

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        int start = 0;
        int end = n-1;

        while(start <= end) {
            int mid = start + (end - start)/2;

            if(start == mid) return nums[start];

            //mid is at odd index
            if(mid % 2 != 0) {
                //right side
                if(mid+1 < n && nums[mid] == nums[mid+1]) {
                    end = mid - 1;
                }
                //left side
                else {
                    start = mid + 1;
                }
            }

            //mid is at even index
            else {
                //left side
                if(mid+1 < n && nums[mid] == nums[mid+1]) {
                    start = mid + 2;
                }
                //right side
                else {
                    end = mid;   // we won't do -1, bcoz we might loose the answer, as it will be at even index
                }
            }
        }
        return -1;
    }
};
