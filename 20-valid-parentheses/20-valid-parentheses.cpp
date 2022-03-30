class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 1)return false;
        std::stack<char> bra; 
        for(auto& i:s){
            if(i == '{' || i == '(' || i=='['){
                bra.push(i);
            }
            else{
                if(bra.empty()) return false;
                if(i == '}' && bra.top() !='{') return false;
                if(i == ']' && bra.top() !='[') return false;
                if(i == ')' && bra.top() !='(') return false;
                bra.pop();  
            }          
        }
        return bra.empty();
    }
};