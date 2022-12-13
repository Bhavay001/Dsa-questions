//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    vector<int> parent,rank;
    public:
    DisjointSet(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    
    // finding parent and path compression
    int findPar(int node){
        if(parent[node]== node){
            return node;
        }
        
        return parent[node] = findPar(parent[node]);
        
    }
    
    void UnionByRank(int u,int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        
        if(ulp_u==ulp_v){
            return;
        }
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
        
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // now we will find the mst sum using kruskal's algorithm
        // we need a data wich stores ({wt,u,v})
        vector<pair<int,pair<int,int>>> edges;
        for(int i =0;i<V;i++){
            // it will store 5 1 2 as well as 5 2 1 as undirected graph but DSU will take care
            for(auto x:adj[i]){
                int adjnode = x[0];
                int wt = x[1];
                int node = i;
                edges.push_back({wt,{node,adjnode}});
            }
        }
        sort(edges.begin(),edges.end());
        DisjointSet ds(V) ;
        int sum = 0;
        for(auto x:edges){
            int wt = x.first;
            int u = x.second.first;
            int v = x.second.second;
            
            int ulp_u = ds.findPar(u);
            int ulp_v = ds.findPar(v);
            
            if(ulp_v == ulp_u){
                continue;
            }
            else{
                ds.UnionByRank(u,v);
                sum += wt;
            }
            
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends