class Solution {
public:
    void DFS(int room, vector<int>& unlocked, vector<vector<int>>&rooms){
        if(unlocked[room] == 1) return;
        unlocked[room] = 1;
        for(int i=0; i<rooms[room].size(); ++i){
            DFS(rooms[room][i], unlocked, rooms);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> unlocked(rooms.size(), 0);
        DFS(0, unlocked, rooms);
        for(auto i:unlocked){
            if(i == 0)
                return false;
        }
        return true;
    }
};