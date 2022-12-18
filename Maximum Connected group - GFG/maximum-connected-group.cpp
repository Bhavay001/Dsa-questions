//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet{
public:
    vector<int> rank,parent,size;
    DisjointSet(int n){
        rank.resize(n,0);
        size.resize(n,1);
        parent.resize(n);
        for(int i =0;i<n;i++){
            parent[i] = i;
        }
    }
    
    // path conpresssion with finding parent done
    int findPar(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }
    
    void UnionBySize(int u,int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        
        // this means they already have same parent/ component
        if(ulp_u == ulp_v){
            return;
        }
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        
        else{
            // same hai rank
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    
    void unionByRank(int u,int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        
        // this means they already have same parent/ component
        if(ulp_u == ulp_v){
            return;
        }
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            // same hai rank
            parent[ulp_v] = ulp_u;
            rank[ulp_v]++;
        }
    }
    
};

class Solution {
  public:
    bool isValid(int row , int col , int n){
        if(row>=0 && row < n && col>=0 && col < n){
            return true;
        }
        return false;
    }
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        
        DisjointSet ds(n*n);
        
        // step 1 we connext the 1s and make them 1 component
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]== 0){
                    continue;
                }
            
                int dx[] = {-1,1,0,0};
                int dy[] = {0,0,-1,1};
                    
                for(int k =0;k<4;k++){
                    int row = dx[k] + i;
                    int col = dy[k] + j;
                        
                    if(isValid(row,col,n) && grid[row][col]==1 ){
                            int rowno = i*n + j;
                            int newrowno = row * n + col;
                            if(ds.findPar(newrowno) != ds.findPar(rowno)){
                                ds.UnionBySize(rowno,newrowno);
                            }
                    }
                }

            }
        }
            // step 2 : now we change 0 to 1 and check left/right/up/down if there are 1s
            int mx = 0;
            for(int i =0;i<n;i++){
                for(int j =0;j<n;j++){
                    if(grid[i][j]==1){
                        continue;
                    }
                    int dx[] = {-1,1,0,0};
                    int dy[] = {0,0,-1,1}; 
                    // we need set because if were direcctly adding size same component was
                    //being added multiple times 
                    set<int> components;
                    
                    for(int k =0;k<4;k++){
                        int row = dx[k] + i;
                        int col = dy[k] + j;
                            
                        if(isValid(row,col,n)){
                            if(grid[row][col]==1){
                                components.insert(ds.findPar(row* n + col));
                            }
                        }
                    }
                    int sizeTotal = 0;
                    for(auto x:components){
                        sizeTotal+= ds.size[x];
                    }
                    mx = max(mx,sizeTotal + 1);
                }
            }
            // if all 1s
            for(int cellno = 0;cellno < n*n ;cellno++){
                mx = max(mx,ds.size[ds.findPar(cellno)]);
            }
            return mx;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends