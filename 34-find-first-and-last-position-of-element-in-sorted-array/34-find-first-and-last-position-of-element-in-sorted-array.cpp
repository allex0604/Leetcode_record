class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //non-decreasing order==>binary search is good
        if(nums.size() == 0) return {-1, -1};
        vector<int> pos;
        int l=0, r=nums.size()-1, mid = 0;
        int check = 0;
        while(l <= r){
            mid = l+(r-l)/2;
            if(nums[mid] == target){
                check = 1;
                break;
            }
            else if(nums[mid] > target){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        if(check == 0) return {-1, -1};
        //find start
        l=0, r=nums.size()-1;
        double target1 = target - 0.5;
        while(l <= r){
            mid = l+(r-l)/2;
            if(nums[mid] > target1){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        cout<<l <<" "<< r<<endl;
        pos.push_back(l);
        //find the last
        l=0, r=nums.size()-1;
        target1 = target + 0.5;
        while(l <= r){
            mid = l+(r-l)/2;
            if(nums[mid] > target1){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        cout<<l <<" "<< r<<endl;
        pos.push_back(r);
        return pos;
    }
};