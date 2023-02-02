class Solution {
    
public:

    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mp;
        for(int i=0;i<order.length();i++){
            mp[order[i]] = i+1;
        }
        
        if(words.size()==1){
            return true;
        }
        
        for(int i=0;i<words.size()-1;i++){
            string word1 = words[i];
            string word2 = words[i+1];
            
            int i1 = 0;
            int i2 = 0;
            
            while(word1[i1]==word2[i2]){
                i1++;
                i2++;
            }
            
            int f1 = mp[word1[i1]];
            int f2 = mp[word2[i2]];
            if(f1>f2){
                return false;
            }
            
        }
        return true;
    }
};