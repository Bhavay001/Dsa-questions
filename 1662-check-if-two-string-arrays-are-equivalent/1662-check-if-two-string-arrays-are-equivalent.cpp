class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string ans = "";
        string ans1 = "";
        for(int i =0;i<word1.size();i++){
            ans += word1[i];
        }
        for(int j =0;j<word2.size();j++){
            ans1 += word2[j];
        }
        
        return ans == ans1;
    }
};