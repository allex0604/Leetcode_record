class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // similar 0-1 kanpsack  
        int n = nums.size();
        int sum =0;
        for(auto &num : nums)
            sum += num;
        // if sum is odd then we cannot find the sum of elements in both subsets is equal
        if ((sum & 1) == 1) {
            return false;
        }
        sum /= 2;
        // dp[i][j] : total sum = j in previous i elements
        vector<vector<int>> dp(n+1, vector<int>(sum+1, false));
        dp[0][0] = true;
        for(int i=1; i<=n; ++i){
            dp[i][0] = true;
            for(int j=1; j<=sum; ++j){
                // case1 : don't choose i-th element
                dp[i][j] = dp[i-1][j];
                // case2 : choose i-th element if satisfy j - nums[i] >= 0 
                if(j - nums[i-1] >= 0 && dp[i-1][j - nums[i-1]] == true)
                    dp[i][j] = true;
            }
        }
        return dp[n][sum];
    }
};