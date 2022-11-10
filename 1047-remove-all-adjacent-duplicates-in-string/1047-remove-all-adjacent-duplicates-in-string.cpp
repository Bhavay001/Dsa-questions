class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        
        for(int i =0;i<s.length();i++){

            if(!st.empty() && st.top()==s[i]){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        string ns = "";
        while(!st.empty()){
            ns.push_back(st.top());
            // cout<<st.top();
            st.pop();
        }

        reverse(ns.begin(), ns.end());
        return ns;
    }
};