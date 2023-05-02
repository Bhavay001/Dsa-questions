class Solution {
public:
    vector<vector<string>> finalans;
    
    void solve(string s,int startIndex, int currIndex,vector<string> &ans){
        if(currIndex == s.size()){
            if(startIndex == s.size()){
                finalans.push_back(ans);
            }
            return;
        }
        
        //check if current string is palindrome or not
        bool ispal = true;
        int l = startIndex;
        int r = currIndex;
        while(l<r){
            if(s[l]!=s[r]){
                ispal = false;
                break;
            }
            else{
                l++;
                r--;
            }
        }
        // the current string is palindrome we will partition it here after then backtrack
        if(ispal){
            ans.push_back(s.substr(startIndex,currIndex - startIndex +1));
            solve(s,currIndex+1,currIndex +1,ans);
            ans.pop_back();
        }  
        // not partition here contibue to take the string
        solve(s,startIndex, currIndex + 1,ans);
    }
    vector<vector<string>> partition(string s) {
        int startIndex = 0;
        int currIndex = 0;
        vector<string> ans;
        // startIndex represents the starting of a string and currIndex will represent the end or curr index of string
        solve(s,startIndex,currIndex,ans);
        return finalans;
    }
};