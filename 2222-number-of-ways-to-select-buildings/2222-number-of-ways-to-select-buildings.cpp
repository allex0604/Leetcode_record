class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.size();
        long long n0 = 0, n1 = 0;
        long long n01 = 0, n10 = 0;
        long long ans = 0;
        
        if(s[0]=='0') n0++;
        else n1++;        
        
        for(int i=1; i<n; ++i){
            if(s[i] == '0'){
                n0++;
                n10 += n1;
                ans += n01;
            }
            else{
                n1++;
                n01 += n0;
                ans += n10;
            }
        }
        return ans;
    }
};