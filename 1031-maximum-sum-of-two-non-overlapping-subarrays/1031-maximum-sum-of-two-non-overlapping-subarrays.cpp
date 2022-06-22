class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> prefix_sum(n+1, 0);
        for(int i=1; i<=n; ++i){
            prefix_sum[i] = prefix_sum[i-1] + nums[i-1];
        }
        return max(MaxSum(prefix_sum, firstLen, secondLen), MaxSum(prefix_sum, secondLen, firstLen));       
    }
    
    int MaxSum(vector<int> p, int f, int s){
        int n = p.size();
        int maxf=0, ans=0;
        
        for(int i=f+s; i<n; ++i){
            maxf = max(maxf, p[i-s] - p[i-s-f]);
            ans = max(ans, maxf + p[i] - p[i-s]);
        }
        
        return ans;
    }
};