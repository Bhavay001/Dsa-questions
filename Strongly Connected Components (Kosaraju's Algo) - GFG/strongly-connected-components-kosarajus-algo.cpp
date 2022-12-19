//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	
	void dfs(int node, vector<int> &visited,vector<int> adj[],stack<int>& st ){
	    visited[node] = 1;
	    for(auto x:adj[node]){
	        if(!visited[x]){
	            dfs(x,visited,adj,st);;
	        }
	    }
	    // when dfs is over
	    st.push(node);
	}
	void dfsnew(int node, vector<int> &visited,vector<int> adjT[]){
	    visited[node] = 1;
	    for(auto x:adjT[node]){
	        if(!visited[x]){
	            dfsnew(x,visited,adjT);
	        }
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        // we need to store the nodes in stack according to their finishing time 
        // because it might happen that 
        vector<int> visited(V,0);
        stack<int> st;
        for(int i =0;i<V;i++){
            if(!visited[i]){
                dfs(i,visited,adj,st);
            }
        }
        // reverse all the edges
        vector<int> adjT[V];
        for(int i =0;i<V;i++){
            visited[i] = 0;
            for(auto x: adj[i]){
                // i -> x
                // now x->i
                adjT[x].push_back(i);
            }
        }
        
        // step 3 perform dfs on bases of finishing time and calculate num of scc
        int scc = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!visited[node]){
                scc++;
                dfsnew(node,visited,adjT);
            }
        }
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends