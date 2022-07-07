class Solution {
public:
    void DFS(vector<vector<int>>& grid, int i, int j, const int m, const int n){
        if(i <0 || j<0 || i>=m || j>=n || grid[i][j] == 1) return;
        grid[i][j] = 1;
        DFS(grid, i+1, j, m, n);
        DFS(grid, i, j+1, m, n);
        DFS(grid, i-1, j, m, n);
        DFS(grid, i, j-1, m, n);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        
        for(int i=0; i<m; ++i){
            if(grid[i][0] == 0)
                DFS(grid, i, 0, m, n);
            if(grid[i][n-1] == 0)
                DFS(grid, i, n-1, m, n);
        }
        
        for(int i=0; i<n; ++i){
            if(grid[0][i] == 0)
                DFS(grid, 0, i, m, n);
            if(grid[m-1][i] == 0)
                DFS(grid, m-1, i, m, n);
        }
        
        for(int i=1; i<m-1; ++i){
            for(int j=1; j<n-1; ++j){
                if(grid[i][j] == 0){
                   DFS(grid, i, j, m, n);
                   ans++; 
                }                    
            }
        }
        return ans;
    }
};