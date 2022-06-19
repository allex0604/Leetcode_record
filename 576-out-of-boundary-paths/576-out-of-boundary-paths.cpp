class Solution {
public:
    bool outOfBounds(int m, int n, int r, int c) {
	    return r < 0 || r >= m || c < 0 || c >= n;
    }
    int findPaths(int m, int n, int maxMove, int r, int c) {
        bool outbound = outOfBounds(m, n, r, c);
        if(outbound || !maxMove) return outbound;
        if(dp[r][c][maxMove] != -1) return dp[r][c][maxMove];  // return if already computed result
	    dp[r][c][maxMove] = 0;   // elements of dp are initalized to -1, so set to 0 before exploring moves
	    for(int i = 0; i < 4; i++) 
		    dp[r][c][maxMove] = (dp[r][c][maxMove] + findPaths(m, n, maxMove-1, r + move[i][0], c + move[i][1])) % mod;
	    return dp[r][c][maxMove];
    }
private:
    int mod = 1e9 + 7;
    int move[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int dp[50][50][51] = {[0 ... 49] = {[0 ... 49] = {[0 ... 50] = -1}}};
};