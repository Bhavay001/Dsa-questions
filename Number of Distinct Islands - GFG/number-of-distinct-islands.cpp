//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
   //row 0 and col0 stores the base which we willl minus to get the same indexes
    void dfs(int row,int col ,vector<vector<int>> &visited,vector<pair<int,int>> &v, vector<vector<int>> &grid,vector<int> dx,vector<int> dy,int row0,int col0){
        
        int n = grid.size();
        int m = grid[0].size();
       
        visited[row][col] = 1;
        v.push_back({row-row0,col -col0});
        for(int i =0;i<4;i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]== 1){
                dfs(nrow,ncol,visited,v,grid,dx,dy,row0,col0);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        // we store the vector of the indexes of consecutive 1s and then push it into the set so the we 
        // only get the distinct ones
       
        set<vector<pair<int,int>>> s;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(!visited[i][j] && grid[i][j] ==1){
                   vector<pair<int,int>> v;
                   dfs(i,j,visited,v,grid,dx,dy,i,j); 
                   s.insert(v);
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends