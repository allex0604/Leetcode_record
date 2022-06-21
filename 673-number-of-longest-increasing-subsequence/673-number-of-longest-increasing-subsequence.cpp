class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> len(n, 1), cnt(n, 1);
        
        for(int j=1; j<n; ++j){
            for(int i=j-1; i>=0; --i){
                if(nums[i] < nums[j]){
                    if(len[i] + 1 > len[j]){
                        len[j] = len[i] + 1;
                        cnt[j] = cnt[i];
                    }
                    else if(len[i] + 1 == len[j]) cnt[j]+= cnt[i];
                }
            }
        }
        
        int ans = 0, m = 0;
        for(int i=0; i<n; ++i){
            if(len[i] > m){
                m = len[i];
                ans = cnt[i];
            }
            else if(len[i] == m){
                ans += cnt[i];
            }
        }
        return ans;
    }
};