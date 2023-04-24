class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp{
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };
        int n = s.size();
        int sum = 0;
        for(int i =0;i<n-1;i++){
            if(mp[s[i]]<mp[s[i+1]]){
                sum -= mp[s[i]];
            }
            else{
                sum +=mp[s[i]];
            }
        }
        sum += mp[s[n-1]];
        return sum;
    }
};