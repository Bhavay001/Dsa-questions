class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        vector<string> v;
        string temp = "";
        set<string> set;
        for(int i=0 ;i<s.size();i++){
            if(s[i]== ' '){
                v.push_back(temp);
                temp = "";
            }
            else{
                temp += s[i];
            }
        }
        if(temp != ""){
            v.push_back(temp);
            temp = "";
        }
        if(v.size()!=pattern.size()){
            return false;
        }
        unordered_map<char,string> mp;
        for(int i =0;i<pattern.size();i++){
            // agar patten letter nahi hai map mai to daal dengai
            if(mp.find(pattern[i])==mp.end()){
                if(set.find(v[i])!=set.end()){
                    return false;
                }
                mp[pattern[i]] = v[i];
                set.insert(v[i]);
            }
            else if(mp.find(pattern[i])!=mp.end() && mp[pattern[i]] != v[i]){
                return false;
            }
        }
        return true;
    }
};