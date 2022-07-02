class Solution {
public:
    vector<int> parent;
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        parent = vector<int>(26, 0);
        for(int i=0; i<26; ++i) parent[i] = i; 
        for(int i=0; i<n; ++i){
            if(equations[i][1] == '=') _union(equations[i][0]-'a', equations[i][3]-'a');
        }
        
        for(int i=0; i<n; ++i){
            if(equations[i][1] == '!'){
                if(find(equations[i][0]-'a') == find(equations[i][3]-'a')) return false;
            }
        }
        return true;
    }
    
    void _union(int a, int b){
        parent[find(a)] = find(b);
    }
    
    int find(int a){
        return parent[a] == a ? a : parent[a] = find(parent[a]);
    }
};