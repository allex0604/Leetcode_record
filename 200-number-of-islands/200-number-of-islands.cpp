class Solution {
public:
    void DFS(vector<vector<char>>& grid, int i, int j, const int m, const int n){
        if(i <0 || j<0 || i>=m || j>=n || grid[i][j] == '0') return;
        grid[i][j] = '0';
        DFS(grid, i+1, j, m, n);
        DFS(grid, i, j+1, m, n);
        DFS(grid, i-1, j, m, n);
        DFS(grid, i, j-1, m, n);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans =0;
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j] == '1'){
                    DFS(grid, i, j, m, n);
                    ans++;
                }
            }
        }
        return ans;
    }
};