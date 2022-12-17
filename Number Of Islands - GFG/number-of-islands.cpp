//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisjointSet{
  public:
  vector<int> rank,parent;
  DisjointSet(int n){
      rank.resize(n,0);
      parent.resize(n);
      for(int i =0;i<n;i++){
        parent[i] = i;
       }
  }
  int findPar(int node){
      if(node == parent[node]){
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
class Solution {
  public:
    bool isValid(int newrow, int newcol , int n, int m){
        if(newrow >=0 && newrow < n && newcol >=0 && newcol <m){
            return true;
        }
        return false;
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        // m*n nodes bna liye aur sabko 0 se initialize kardia
        DisjointSet ds(m*n);
        // visited matrix sab 0 initialized;
        int vis[n][m];
        memset(vis , 0, sizeof vis);
        int cnt = 0;
        vector<int> ans;
        for(auto x:operators){
            int row = x[0];
            int col = x[1];
            // agar ye node pehle se visited hai to fir to same count push kardo
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            
            vis[row][col] = 1;
            cnt++;
            
            // now we have to chwck in all 4 directions if they are visited we join them and decrease cnt
            // ek aur cheez dekhni padhegi agar parent different hon to hi join karengai
            
            int dx[] = {-1,1,0,0};
            int dy[] = {0,0,-1,1};
            
            for(int i =0;i<4;i++){
                int newrow = row + dx[i];
                int newcol = col + dy[i];
                
                if(isValid(newrow,newcol,n,m)){
                    if(vis[newrow][newcol] == 1){
                        int rowno = row * m + col;
                        int newrowno = newrow * m + newcol;
                        if(ds.findPar(rowno)!= ds.findPar(newrowno)){
                            ds.UnionByRank(rowno,newrowno);
                            cnt--;
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends