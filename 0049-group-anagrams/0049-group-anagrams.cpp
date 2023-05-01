class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;
        
        for(int i =0;i<strs.size();i++){
            string s = strs[i];
            string s1 = strs[i];
            sort(s1.begin(),s1.end());
            mp[s1].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};