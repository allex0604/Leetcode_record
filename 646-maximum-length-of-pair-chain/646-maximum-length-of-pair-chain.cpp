class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        int ans = 0;
        vector<int> dp(pairs.size(), 1);
        sort(pairs.begin(), pairs.end(), compare);
        for(int i=0; i<pairs.size(); ++i){
            for(int j=0; j<i; ++j){
                if(pairs[j][1] < pairs[i][0])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};