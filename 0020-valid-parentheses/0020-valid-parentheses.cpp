class Solution {
public:
    bool check(char ch1,char ch2){
        if(ch1 == '(' && ch2 == ')' || ch1 == '[' && ch2 == ']' || ch1 == '{' && ch2 == '}'){
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        stack<int> st;
        for(int i =0;i<s.size();i++){
            if(s[i]=='(' || s[i] == '[' || s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(st.size()==0){
                    return false;
                }
                char ch = st.top();
                if(check(ch,s[i])){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.size()>0){
            return false;
        }
        return true;
    }
};