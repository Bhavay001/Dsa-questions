class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights[0].size();
        vector<pair<int,int>> adj[n];
        
        for(auto x:flights){
            int u = x[0];
            int v= x[1];
            int dist = x[2];
            
            adj[u].push_back({v,dist});
        }

        vector<int> distance(n,INT_MAX);
        
    
        // {steps,{node,dist}}
        queue<pair<int,pair<int,int>>> q;
        
        q.push({0,{src,0}});
        distance[src] = 0;
        
        while(!q.empty()){
            int steps = q.front().first;
            int node = q.front().second.first;
            int dis = q.front().second.second;
            
            q.pop();
            // when steps are greater than k we do not want to calculate further
            // if(steps > k){
            //     continue;
            // }
            for(auto x:adj[node]){
                int wt = x.second;
                int adjnode = x.first;
                if(distance[adjnode]> dis + wt && steps<=k ){
                    distance[adjnode] = dis + wt;
                    q.push({steps+1,{adjnode,dis+wt}});
                }
            }
        }
        if(distance[dst]==INT_MAX){
            return -1;
        }
        return distance[dst];
    }
};