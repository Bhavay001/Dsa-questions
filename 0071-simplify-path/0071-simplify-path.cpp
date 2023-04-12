class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        for(int i = 0;i<path.size();i++){
            
            if(path[i] == '/'){
                continue;
            }
            string curr = "";
            while(i<path.size() && path[i] !='/'){
                curr += path[i];
                i++;
            }
            if(curr == "."){
                continue;
            }
            else if(curr == ".."){
                if(st.size()!=0){
                    st.pop();
                    curr = "";
                }
            }
            else{
               st.push(curr);
            } 
        }
        

        stack<string> st1;
        while(!st.empty()){
            st1.push(st.top());
            st.pop();
        }
        
        string ans = "";
        if(st1.empty()){
           ans += '/'; 
        }
        else{
            while(!st1.empty()){
                ans += '/';
                ans += st1.top();
                st1.pop();

            }
        }
        return ans;
    }
};