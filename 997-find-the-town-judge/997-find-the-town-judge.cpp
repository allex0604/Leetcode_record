class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // directly graph : indegree - outdegree = n-1
        vector<int> degree(n+1, 0);
        for(auto& p:trust){
            degree[p[0]]--;
            degree[p[1]]++;
        }
        for(int i=1; i<n+1; ++i){
            if(degree[i] == n-1)
                return i;
        }
        return -1;        
    }
};