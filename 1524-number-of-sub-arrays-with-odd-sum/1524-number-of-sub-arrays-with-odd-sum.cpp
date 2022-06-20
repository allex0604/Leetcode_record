class Solution {
public:
    int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n);
        dp[0] = (arr[0]%2==0)?0:1;
        long long int ans=dp[0];
        for(int i=1; i < n; ++i){
            if(arr[i] % 2 == 0){
                dp[i] = dp[i-1];
            }
            else{
                dp[i] = i - dp[i-1] + 1;
            }
            ans += dp[i];
        }
        
        return ans % mod;
    }
};