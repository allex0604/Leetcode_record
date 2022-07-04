class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), count(n, 1);
        int longest = 0, ans = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<=i-1; ++j){
                if(nums[i] > nums[j]){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                    else if(dp[i] == dp[j] + 1) count[i] += count[j];
                }
            }
            if(dp[i] > longest){
                ans = count[i];
                longest = dp[i];
            }
            else if(dp[i] == longest) ans += count[i];
        }
        return ans;
    }
};