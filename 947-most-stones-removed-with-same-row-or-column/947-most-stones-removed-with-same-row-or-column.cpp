class Solution {
public:
    vector<int> parent;
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_map<int, vector<int>> row, col;
        for(int i=0; i<n; ++i){
            row[stones[i][0]].push_back(i);
            col[stones[i][1]].push_back(i);
        }
        
        for(int i=0; i<n; ++i)  parent.push_back(i);
        
        for(int i=0; i<n; ++i){
            for(auto j : row[stones[i][0]]) _union(i, j);
            for(auto j : col[stones[i][1]]) _union(i, j);
        }
        
        unordered_set<int> unique;
        for(auto i : parent) unique.insert(find(i));
        
        return n - unique.size();
    }
    
    void _union(int a, int b){
        parent[find(a)] = find(b);
    }
    
    int find(int a){
        return parent[a] == a ? a : parent[a] = find(parent[a]);
    }
};