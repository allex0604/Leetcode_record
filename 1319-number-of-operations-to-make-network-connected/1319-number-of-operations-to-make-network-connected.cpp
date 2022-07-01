class Solution {
public:
    vector<int> parent;
    int makeConnected(int n1, vector<vector<int>>& connections) {
        int n = connections.size();
        parent = vector<int>(n1, 0);
        for(int i=0; i<n1; ++i) parent[i] = i;
        
        int remove = 0;
        for(int i=0; i<n; ++i){
            remove += _union(connections[i][0], connections[i][1]);
        }
        
        unordered_set<int> tree;
        for(auto i : parent) tree.insert(find(i));
        //cout<<tree.size()-1 << " " << remove;
        return tree.size()-1 <= remove ? tree.size()-1 : -1;
    }
    
    int _union(int a, int b){
        if(parent[find(a)] == parent[find(b)]) return 1;
        else{
            parent[find(a)] = find(b);
        }
        return 0;
    }
    
    int find(int a){ return parent[a] == a ? a : parent[a] = find(parent[a]);}
};