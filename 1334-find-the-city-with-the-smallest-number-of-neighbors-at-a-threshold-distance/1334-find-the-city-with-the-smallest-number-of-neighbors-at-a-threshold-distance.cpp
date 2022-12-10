class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int> (n,INT_MAX));
        
        // first we have to make initial matrix from the given
        for(auto x:edges){
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        
        // for itself to itself
        for(int i=0;i<n;i++){
            dist[i][i] = 0;
        }
        
        // now applying floyds warshall algo
        for(int via=0;via<n;via++){
            for(int i =0;i<n;i++){
                for(int j =0;j<n;j++){
                    if(dist[i][via]==INT_MAX || dist[via][j]==INT_MAX){
                        continue;
                    }
                    dist[i][j] = min(dist[i][j],dist[i][via] + dist[via][j]);
                }
            }
        }
        
        // here we just needed to store the smallest number of cities
        int citynum = -1;
        int maxcount = n;
        for(int i = 0;i<n;i++){
            int count = 0;
            for(int j =0;j<n;j++){
                if(dist[i][j]<=distanceThreshold){
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