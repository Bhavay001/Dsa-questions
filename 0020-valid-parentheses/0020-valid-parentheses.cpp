class Solution {
public:
    bool check(char ch2, char ch1){
        if(ch1 == '(' && ch2 == ')' || ch1 == '[' && ch2 == ']' || ch1 == '{' && ch2 == '}'){
            return true;
        }
        else{
            return false;
        }
    }
    bool isValid(string s) {
        stack<int> st;
        int i =0;
        while(i<s.length()){
            if(st.empty()){
                st.push(s[i]);
                i++;
            }
            else{
                if(check(s[i],st.top())){
                    while(!st.empty() && check(s[i],st.top())){
                        st.pop();
                        i++;
                    }
                }
                else{
                    st.push(s[i]);
                        i++;
                }
            }
        }
        if(!st.empty()){
            return false;
        }
        else{
            return true;
        }
    }
};