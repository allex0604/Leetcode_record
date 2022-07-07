class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total_sum=0, sum=0, n = stones.size();
        for(auto& stone:stones){
            total_sum += stone;
        }
        sum = total_sum / 2;
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        dp[0][0] = 1;
        for(int i=1; i<n+1; ++i){
            dp[i][0] = 1;
            for(int j=1; j<sum+1; ++j){
                // case1
                dp[i][j] = dp[i-1][j];
                // case2
                if(j >= stones[i-1] && dp[i-1][j-stones[i-1]] == 1)
                    dp[i][j] = 1;
            }
        }
        int ans =0;
        for(int i=sum; i>=0; --i){
            if(dp[n][i] == 1){
                ans = total_sum - 2 * i;
                break;
            }
        }
        return ans;
    }
};