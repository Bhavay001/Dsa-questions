class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D',500},
            {'M',1000}
        };
        int ans = 0;
        for(int i =0;i<s.size()-1;i++){
            if(mp[s[i+1]] <= mp[s[i]]){
                ans += mp[s[i]];
            }
            else{
                ans -= mp[s[i]];
            }
        }
        ans += mp[s[s.size()-1]];
        return ans;
      
    }
};