class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // there can be 2 things that we need to check
        //1) a -> dog
        //  a-> cat this cannot happen
        //2) a-> dog
        // b->dog
        vector<string> v;
        string str = "";
        for(int i =0;i<s.size();i++){
            if(s[i]== ' '){
                v.push_back(str);
                str = "";
            }
            else{
                str+=s[i];
            }
        }
        
        if(str.size()!=0){
            v.push_back(str);
            str = "";
        }
        
        if(v.size()!=pattern.size()){
            return false;
        }
        
        // now we have all the string words in a vector
        // we will store the mapping of the character to the word and if the word is already present 
        map<char,string> mp;
        set<char> st1;
        set<string> st2; 
        for(int i =0;i<pattern.size();i++){
            if(mp.find(pattern[i])== mp.end()){
                mp[pattern[i]] = v[i];
                st1.insert(pattern[i]);
                st2.insert(v[i]);
            }
            else{
                if(mp[pattern[i]]!=v[i]){
                    return false;
                }
            }
        }
        if(st1.size()!=st2.size()){
            return false;
        }
        return true;
    }
};