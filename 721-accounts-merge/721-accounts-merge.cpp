class Solution {
public:
    vector<int> parent;
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> email2id;
        parent = vector<int>(1001);
        for(int i=0; i<n; ++i){
            parent[i] = i;
            for(int j=1; j<accounts[i].size(); ++j){
                if(email2id.find(accounts[i][j]) != email2id.end()){
                    parent[find(i)] = find(email2id[accounts[i][j]]);
                }
                else{
                    email2id[accounts[i][j]] = parent[i];
                }
                    
            }
        }
        
        unordered_map<int, vector<string>> resultant_map;            
        for(auto it: email2id){
            int uniq_id = find(it.second);
            resultant_map[uniq_id].push_back(it.first);
        }
        
        vector<vector<string>> ans;
        for(auto it: resultant_map){
            vector<string> email = it.second;
                
            sort(email.begin(), email.end());
                
            email.insert(email.begin(), accounts[it.first][0]);
                
            ans.push_back(email);
        }
        return ans;
    }
    
    int find(int a){
        return parent[a]==a ? a : parent[a] = find(parent[a]);
    }
    
};