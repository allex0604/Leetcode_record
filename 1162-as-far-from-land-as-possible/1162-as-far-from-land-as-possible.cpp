class Solution {
public:
    vector<int> DIR = {0, 1, 0, -1, 0};
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[i].size(); ++j){
                if(grid[i][j]==1) {
                    q.emplace(i, j);
                    grid[i][j] = 0;
                }
                else{
                    grid[i][j] = -1;
                }
            }
        }
        
        int ans = -1;
        while(!q.empty()){
            auto [r, c] = q.front(); q.pop();
            for(int i=0; i<4; ++i){
                int nr = r + DIR[i], nc = c + DIR[i+1];
                if(nr < 0 || nr==grid.size() || nc < 0 || nc==grid[0].size() || grid[nr][nc] != -1)
                    continue;
                grid[nr][nc] = grid[r][c] + 1;
                ans = max(ans, grid[nr][nc]);
                q.emplace(nr, nc);
            }
        }
        return ans;
    }
};