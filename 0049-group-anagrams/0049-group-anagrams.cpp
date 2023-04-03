class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
    /* Consider example 1 : strs = ["eat","tea","tan","ate","nat","bat"]
            we will like this in map   
            aet -- eat, tea, ate
            ant -- tan, nat
            abt -- bat */
        
        unordered_map<string,vector<string>> mp;
        
        for(int i =0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            
            mp[s].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        for(auto x:mp){
            ans.push_back(x.second);
        }
        
        return ans;
    }
};