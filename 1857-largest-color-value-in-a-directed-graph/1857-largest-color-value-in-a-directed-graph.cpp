class Solution {
public:
    // this is a toposort question
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        // we will start with the nodes whose indegrees are 0
        // colors size tells us the number of nodes
        int n = colors.size();
        vector<int> indegrees(n,0);
        vector<vector<int>> adj(n,vector<int>());
        // creating an adjacency list from the edges
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            indegrees[edge[1]]++;
        }
        
        queue<int> q;
        // we will push all the nodes with indegree 0;
        for(int i =0;i<n;i++){
            if(indegrees[i]==0){
                q.push(i);
            }
        }
        
        // i have to provide the information about the color to the child
        // so the parent has to provide the color count to the child as we need to find
        // the longest color value path parents can be many ans colors can be atmost 26(letter)
        // and as we go down we need color value count of each color
        
        // for 1 node 26 colors are possible for n nodes count[n][26]
        vector<vector<int>> counts(n,vector<int>(26,0));
        
        for(int i =0;i<n;i++){
            counts[i][colors[i] - 'a']++;
        }
        
        int maxcount = 0;
        int visited = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            visited++;
            for(int v:adj[node]){
                for(int i =0;i<26;i++){
                    counts[v][i] = max(counts[v][i],counts[node][i] +(colors[v]- 'a' == i ?1 :0));
                    
                }
                indegrees[v]--;
                if(indegrees[v]==0){
                    q.push(v);
                }
            }
            maxcount = max(maxcount,*max_element(counts[node].begin(),counts[node].end()));
        }
        return visited == n?maxcount : -1;
    }
};