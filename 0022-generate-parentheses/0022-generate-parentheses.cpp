class Solution {
public:
    
    void solve(vector<string> &ans,int open,int close,string op){
        // base case
        if(open == 0 && close == 0){
            ans.push_back(op);
            return;
        }
        if(open!=0){
            solve(ans,open-1,close,op + '(');
        }
        if(close>open){
            solve(ans,open,close-1,op + ')');
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open = n;
        int close = n;
        string op = "";
        solve(ans,open,close,op);
        return ans;
    }
};