class Solution {
public:
    
    bool is_similar(string s1, string s2){
        int count = 0;
        for(int i = 0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                count++;
            }
        }
        if(count<=2){
            return true;
        }
        else{
            return false;
        }
    }
    void dfs(int node,vector<string> & strs, vector<int> &vis){
        vis[node] = 1;
        
        // the strings which have less than or equal to 2 different characters are similar as they can be 
        //swapped to make then equal
        
        // so we traverse the neighbours (strings) which are similar(have edges connected) with 
        // each other and make then visited
        for(int i=0;i<strs.size();i++){
            if(!vis[i]){
                if(is_similar(strs[node],strs[i])){
                    dfs(i,strs,vis);
                }
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int ans = 0;
        vector<int> vis(n,0);
        // we just needed to find the number of connected components in a graph where a component is the strings 
        //which are similar to atleast one of each other 
        
        // like in the examle the tars,rats,arts make a components where (tars -> rats -> arts) tars is 
        //not directly similar to arts ans the second component is star
        for(int i =0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,strs,vis);
            }
        }
        return ans;
    }
};