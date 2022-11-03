class Solution {
public:
    
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    void solve(int index, string s, vector<vector<string>>& ans, vector<string> &path){
        // base case if the index/partioning index has reached euqal to the size of the string
        if(index == s.length()){
            ans.push_back(path);
                return;
        }
        // now  starting from the index if it is possible to divide
        for(int i =index;i<s.length();i++){
            if(isPalindrome(s,index,i)){
                path.push_back(s.substr(index,i - index +1));
                solve(i+1,s,ans,path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        // 0 is the index
        solve(0,s,ans, path);
        return ans;
    }
};