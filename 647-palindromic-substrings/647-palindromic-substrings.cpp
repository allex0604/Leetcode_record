class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
            ans++;
        }
        
        for(int l=1; l<n; ++l){
            for(int i=0; i<l; ++i){
                if((i+1 == l && s[i]==s[l]) ||(s[i] == s[l] && dp[i+1][l-1] == 1)){
                    dp[i][l] = 1;
                    ans++;
                }
            }
        }
        return ans;
    }
};