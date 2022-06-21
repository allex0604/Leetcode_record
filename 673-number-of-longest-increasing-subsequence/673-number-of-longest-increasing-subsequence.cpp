class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, m = 0;
        vector<int> len(n, 1), cnt(n, 1);
        
        for(int j=0; j<n; ++j){
            for(int i=j-1; i>=0; --i){
                if(nums[i] < nums[j]){
                    if(len[i] + 1 > len[j]){
                        len[j] = len[i] + 1;
                        cnt[j] = cnt[i];
                    }
                    else if(len[i] + 1 == len[j]) cnt[j]+= cnt[i];
                }
            }
            if(len[j] > m){
                m = len[j];
                ans = cnt[j];
            }
            else if(len[j] == m){
                ans += cnt[j];
            }
        }
        return ans;
    }
};