class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<std::pair<int, int>> lds(n);
        sort(nums.begin(), nums.end());
        int max = 0, final_index = -1;
        
        for(int i=0; i<n; ++i){
            lds[i].first = -1;
            lds[i].second = 1;
            for(int j=i-1; j>=0; --j){
                if(nums[i] % nums[j] == 0){
                    if(lds[j].second + 1 > lds[i].second){
                        lds[i].first = j;
                        lds[i].second = lds[j].second + 1;
                    }
                }
            }
            if(max < lds[i].second){
                max = lds[i].second;
                final_index = i;
            }
        }
        
        vector<int> ans(max, 0);
        while(max > 0){
            ans[max-1] = nums[final_index];
            final_index = lds[final_index].first;
            max--;
        }
        return ans;
    }
};