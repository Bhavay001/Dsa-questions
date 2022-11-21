class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<int,int>> adj[n];
        for(auto x:roads){
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<int> ways(n,0);
        vector<long long> distance(n,LONG_MAX);
        // {dist,node}
        priority_queue<pair<long long,long long> , vector<pair<long long,long long>> , greater<pair<long long,long long>>>pq;
       
        distance[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        int mod = (int)(1e9 + 7);
        while(!pq.empty()){
            int node = pq.top().second;
            long long wt = pq.top().first;
            
            pq.pop();
            
            for(auto x: adj[node]){
                int adjnode = x.first;
                long long newwt = x.second;
                

                // this meeans this is the first time i am coming with this short distance 
                if(newwt + wt < distance[adjnode]){
                    
                    distance[adjnode] = newwt + wt;
                    pq.push({wt+newwt,adjnode});
                    // abhi nye nye path par aayen hain to jo pichle node kai ways hain utnai hi hongai
                    ways[adjnode] = ways[node];
                }
                // agar pehle bhi same distance par aa chuke hain to matlab iskai bhi node kai ways add karne hongai kyonki ye path 
                // dusra hai abhi kai wahys + pichle waale kai add kardene hain
                else if(newwt + wt == distance[adjnode]){
                    ways[adjnode] = (ways[adjnode] + ways[node])%mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};