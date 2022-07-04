class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> val(10001, 0);
        for(auto& num : nums){
            val[num] += num;
        }
        
        int take = 0, skip = 0;
        for(int i=0; i<val.size(); ++i){
            int takei = skip + val[i];
            int skipi = max(take, skip);
            take = takei;
            skip = skipi;
        }
        
         return max(take, skip);
    }
};