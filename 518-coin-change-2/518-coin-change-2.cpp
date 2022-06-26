class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> num(n+1, vector<int>(amount+1, 0));
        num[0][0] = 1;
        for(int i=1; i<=n; ++i){
            num[i][0] = 1;
            for(int j=1; j<=amount; ++j){
                if(j - coins[i-1] >= 0)
                    num[i][j] = num[i-1][j] + num[i][j - coins[i-1]];
                else
                    num[i][j] = num[i-1][j];
            }
        }
        
        return num[n][amount];
    }
};