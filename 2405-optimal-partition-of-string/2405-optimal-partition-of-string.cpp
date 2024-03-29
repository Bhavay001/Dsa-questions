class Solution {
public:
    int partitionString(string s) {
        map<char,int> mp;
        int ans = 1;
        for(int i =0;i<s.size();i++){
            mp[s[i]]++;
            if(mp[s[i]]>1){
                ans++;
                mp.clear();
                mp[s[i]] = 1;
            }
        }
        return ans;
    }
};

