class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> nodes(2000);
        for(int i=0; i<2000; ++i){
            nodes[i] = i;
        }
        
        vector<int> ans;
        for(auto& e:edges){
            int n1 = e[0], n2 = e[1];
            while(n1 != nodes[n1]) n1 = nodes[n1];
            while(n2 != nodes[n2]) n2 = nodes[n2];
            if(n1 == n2) ans = e;
            else{
                nodes[n1] = n2;
            }
        }
        return ans;
        
    }
};