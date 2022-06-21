class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        // base case
        dp[1] = arr[0];
        for(int i=2; i<=n; ++i){
            int submax = 0;
            for(int j=1; j<=k; ++j){
                if(i-j >= 0){
                    submax = max(submax, arr[i-j]);
                    dp[i] = max(dp[i], dp[i-j] + submax * j);
                }
            }
        }
        return dp[n];
    }
};