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
        
        string ans = "";
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        if(ans.size()==0){
            ans = "/";
        }
     
        return ans;
    }
};