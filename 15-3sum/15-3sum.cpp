class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        if(nums.size() < 3) return {};
        if(nums[0] > 0) return {};
        for(int i = 0 ; i < nums.size() ; ++i){ 
            if(nums[i] > 0) break;
            if(i > 0 && nums[i - 1] == nums[i])continue;
            int l = i + 1, r = nums.size()-1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    int L1 = nums[l], R1 = nums[r];
                    while(l < r && nums[l] == L1) l++;
                    while(l < r && nums[r] == R1) r--;
                }
                else if(sum > 0){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return ans;
    }
};