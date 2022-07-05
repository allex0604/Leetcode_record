class Solution {
public:
    static bool compare(vector<int> &a, vector<int>& b){
        return (a[0]==b[0]? a[1]>b[1] : a[0]<b[0]);
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size(), ans = 0;
        vector<int> dp;
        sort(envelopes.begin(), envelopes.end(), compare);
        
        for (auto& env : envelopes) {
            int height = env[1];
            int left = lower_bound(dp.begin(), dp.end(), height) - dp.begin();
            if (left == dp.size()) dp.push_back(height);
            dp[left] = height;
        }
        return dp.size();
    }
};