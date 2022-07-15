/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int DFS(vector<Employee*> employees, vector<int> &pos, int id){
        int ans = employees[pos[id]]->importance;
        for(auto &i:employees[pos[id]]->subordinates)
            ans += DFS(employees, pos, i);
        return ans;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        int ans = 0;
        vector<int> pos(2001, 0);
        for(int i=0; i<employees.size(); ++i){
            pos[employees[i]->id] = i;
        }
        for(auto& e:employees){
            if(e->id == id){
                ans = e->importance;
                for(auto &i:e->subordinates)
                    ans += DFS(employees, pos, i);
            }
        }
        return ans;
    }
};