class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> num(amount+1, 0);
        
        num[0] = 1;
        for(auto& coin:coins){
            for(int i=coin; i<=amount; ++i){
                num[i] += num[i-coin];
            }
        }
        
        return num[amount];
    }
};