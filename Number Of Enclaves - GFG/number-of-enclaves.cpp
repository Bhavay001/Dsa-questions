//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(int row,int col,vector<vector<int>> &grid,int n ,int m){
        grid[row][col] = 0;
        for(int i =0;i<4;i++){
            vector<int> dx = {-1,1,0,0};
            vector<int> dy = {0,0,-1,1};
            int newrow = row + dx[i];
            int newcol = col + dy[i];
            
            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && grid[newrow][newcol]==1){
                dfs(newrow,newcol,grid,n,m);
            }
            
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i =0;i<n;i++){
            if(grid[i][0]==1){
                dfs(i,0,grid,n,m);
            }
            if(grid[i][m-1]==1){
                dfs(i,m-1,grid,n,m);
            }
        }
        for(int j =0;j<m;j++){
            if(grid[0][j]==1){
                dfs(0,j,grid,n,m);
            }
            if(grid[n-1][j]==1){
                dfs(n-1,j,grid,n,m);
            }
        }
        int count = 0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == 1){
                    count ++;
                }
            }
        }
        return count;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends