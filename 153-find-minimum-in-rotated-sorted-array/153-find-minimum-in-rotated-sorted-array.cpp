class Solution {
public:
    int findMin(vector<int>& nums) {
        int first = nums[0], l = 0, r = nums.size()-1, mid = 0, target = -5001;
        while(l <= r){
            mid = l + (r - l) / 2;
            if(nums[mid] >= first){
                if(target < nums[mid]  && target >= nums[l]) r = mid - 1;
                else l = mid + 1;
            }
            else{
                if(target > nums[mid]  && target <= nums[r]) l = mid - 1;
                else r = mid - 1;
            }
        }
        return l==nums.size()? nums[0] : nums[l];
    }
};