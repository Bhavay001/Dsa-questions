class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>> adj[n];
        
        // first we have to make initial matrix from the given
        for(auto x:edges){
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        int citynum = -1;
        int maxcount = n;
        
        // now applying dijaktra's algo
        for(int i =0;i<n;i++){
            vector<int> distance(n,INT_MAX);
            pq.push({0,i});
            distance[i] = 0;
            while(!pq.empty()){
                int node = pq.top().second;
                int wt = pq.top().first;
                pq.pop();
                
                for(auto x:adj[node]){
                    int newnode = x.first;
                    int adjwt = x.second;
                    
                    if(distance[node] + adjwt < distance[newnode]){
                        distance[newnode] = distance[node] + adjwt;
                        pq.push({distance[newnode],newnode});
                    }
                }
            }

            // here we just needed to store the smallest number of cities
            int count = 0;
            for(int j =0;j<n;j++){
                if(distance[j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=maxcount){
                citynum = i;
                maxcount = count;
            }
        }
            
     
        return citynum;
    }
};