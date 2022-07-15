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
    void DFS(int id, unordered_map<int, Employee*> &m, int &sum){
        sum += m[id]->importance;
        for(auto &sub:m[id]->subordinates) DFS(sub, m, sum);
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> m;
        for(auto& e:employees){
            m[e->id] = e;
        }
        int ans = 0;
        DFS(id, m, ans);
        return ans;
    }
};