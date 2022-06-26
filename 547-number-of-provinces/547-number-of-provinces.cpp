class Solution {
public:
    vector<int> parent;
    
    int find_root(int index){
        if(parent[index] == -1) return index;
        return parent[index] = find_root(parent[index]);
    }
    
    void _union(int a, int b){
        int root_a=find_root(a);
        int root_b=find_root(b);
        
        if(root_a != root_b)
            parent[root_a] = root_b;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        parent = vector<int>(n, -1);
        
        for(int i=0; i<n; ++i){
            for(int j=i; j<n; ++j){
                if(isConnected[i][j] == 1)
                    _union(i, j);
            }
        }
        
        int ans=0;
        for(auto& i:parent){
            if(i==-1)
                ans++;
        }
        return ans;
    }
};