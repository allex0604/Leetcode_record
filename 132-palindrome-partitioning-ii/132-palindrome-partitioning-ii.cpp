class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> dp1(n, 0);
        
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        
        for(int l=1; l<n; ++l){
            dp1[l] = l;
            for(int i=0; i<=l; ++i){
                if(s[i]==s[l] && (l-i<2 || dp[i+1][l-1])){
                    dp[i][l] = 1;
                    if(i == 0)
                        dp1[l] = 0;
                    else if(dp1[l] > dp1[i-1] + 1){
                        dp1[l] = dp1[i-1] + 1;
                    }                    
                }
            }
        }
        for(auto i:dp1){
            cout<<i<<" ";
        }
        return dp1[n-1];
    }
};