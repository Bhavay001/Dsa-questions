class Solution {
private:
    void dfs(int node, vector<int> &visited,vector<int> adj[]){
        visited[node] = 1;
        for(auto x:adj[node]){
            if(!visited[x]){
                dfs(x,visited,adj);
            }
        }  
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        // converted adjacencty matrix to list
        int n = isConnected.size();
        vector<int> adj[n];
        vector<int> visited(n,0);
        for(int i =0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        
        // now simply i checked for number of components and it will be my answer
        int count = 0;
        for(int i =0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i,visited,adj);
            }
        }
        return count;
    }
};