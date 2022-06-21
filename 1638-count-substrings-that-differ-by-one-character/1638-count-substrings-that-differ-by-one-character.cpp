class Solution {
public:
    int countSubstrings(string s, string t) {
        int n = s.size(), m = t.size(), ans = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        vector<vector<int>> dp1(n+1, vector<int>(m+1, 0));
                
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    dp1[i][j] = dp1[i-1][j-1];
                }
                else{
                    dp1[i][j] = dp[i-1][j-1] + 1;
                }
                ans += dp1[i][j];
            }
        }
        return ans;
    }
};