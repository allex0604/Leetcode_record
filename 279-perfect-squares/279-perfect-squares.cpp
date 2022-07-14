class Solution {
public:
    int numSquares(int n) {
        vector<int> ans(n+1, 1001);
        vector<int> perfect_squ;
        for(int i=1; i<=100; ++i){
            perfect_squ.push_back(i*i);
        }
        
        ans[0] = 0;
        for(int i=1; i<=n; ++i){
            for(auto& p:perfect_squ){
                if(i - p < 0) break;
                else{
                    ans[i] = min(ans[i-p]+1, ans[i]);
                }
            }
        }
        return ans[n];
    }
};