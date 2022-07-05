class Solution {
public:
    int DFS(int n, int headID, vector<int>& manager, vector<int>& informTime){
        return (manager[n]==-1)? informTime[n] : informTime[n] + DFS(manager[n], headID, manager, informTime);
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans = 0;
        for(int i=0; i<informTime.size(); ++i){
            int temp = 0;
            if(informTime[i] == 0)
                temp = DFS(i, headID, manager, informTime);
            ans = max(ans, temp);
        }
        return ans;
    }
};