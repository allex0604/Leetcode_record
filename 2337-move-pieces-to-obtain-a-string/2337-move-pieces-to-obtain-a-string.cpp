class Solution {
public:  
    bool canChange(string start, string target) {
        queue<pair<char, int>> ss, ts;
        for(int i=0; i<start.size(); ++i){
            if(start[i] != '_') ss.push({start[i], i});
        }
        for(int i=0; i<target.size(); ++i){
            if(target[i] != '_') ts.push({target[i], i});
        }
        
        if(ss.size() != ts.size())return false;
        
        while(ss.size()){
            pair<char, int> ps, pt;
            ps = ss.front();
            pt = ts.front();
            
            ss.pop();
            ts.pop();
            
            if(ps.first != pt.first) return false;
            if(ps.first == 'L' && ps.second < pt.second) return false;
            else if(ps.first == 'R' && ps.second > pt.second){
                return false;
            }
        }
        return true;
    }
};