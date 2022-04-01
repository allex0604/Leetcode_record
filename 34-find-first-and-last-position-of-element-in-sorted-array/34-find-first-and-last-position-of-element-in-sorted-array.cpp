class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //non-decreasing order==>binary search is good
        vector<int> pos(2, -1);
        int l=0, r=nums.size()-1, mid = 0;
        while(l <= r){
            mid = l+(r-l)/2;
            if(nums[mid] > target){
                r = mid - 1;
            }
            else if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                if(mid == l || nums[mid-1] != nums[mid]){
                    pos[0] = mid;
                    break;
                }
                else{
                   pos[0] = mid-1;
                   r = mid -1; 
                }            
            }
        }
        l=0, r=nums.size()-1, mid = 0;
        while(l <= r){
            mid = l+(r-l)/2;
            if(nums[mid] > target){
                r = mid - 1;
            }
            else if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                if(mid == r || nums[mid] != nums[mid+1]){
                    pos[1] = mid;
                    break;
                }
                else{
                   pos[1] = mid + 1;
                   l = mid + 1; 
                }            
            }
        }        
        return pos;
    }
};