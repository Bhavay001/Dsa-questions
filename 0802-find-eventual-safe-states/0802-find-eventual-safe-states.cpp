class Solution {
public:
    // anyone who is part of cycle is a not safe node
    // any one which leads to a cycle (outgounf edges) is not a safe node
    //rest all are safe nodes
    
    bool dfs(int node, vector<int> &visited, vector<int> &dfsvisited, vector<int> &safevisited,vector<vector<int>>& graph){
        visited[node] = 1;
        dfsvisited[node] = 1;
        
        for(auto x:graph[node]){
            if(!visited[x]){
                if(dfs(x,visited,dfsvisited,safevisited,graph)==true){
                    safevisited[node] = 1;
                    return true;
                }  
            }
            else if(visited[x] && dfsvisited[x]){
                safevisited[node] = 1;
                return true;
            }
        }
        dfsvisited[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,0);
        vector<int> dfsvisited(n,0);
        vector<int> safevisited(n,0);
        
        for(int i =0;i<graph.size();i++){
            if(!visited[i]){
                dfs(i,visited,dfsvisited,safevisited,graph);
            }
        }      
        vector<int> ans;
        for(int i =0;i<safevisited.size();i++){
            if(!safevisited[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};