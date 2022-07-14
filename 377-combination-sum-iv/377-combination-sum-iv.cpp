class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // need to use unsigned int to avoid overflow
        vector<unsigned int> dp(target+1, 0);
        dp[0] = 1;
        for(int i=1; i<=target; ++i){
            for(auto &num:nums){
                if(num<=i){
                    dp[i] += dp[i-num];
                }
            }
        }
        return dp[target];
    }
};