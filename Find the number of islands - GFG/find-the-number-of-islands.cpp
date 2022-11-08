//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
  private:
    void bfs(int row, int col ,vector<vector<int>> &visited, vector<vector<char>> &grid){
        visited[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // traverse the neighbousrs since we have 8 neighnbours we use loops (shorttrick)
            for(int deltarow=-1;deltarow<=1;deltarow++){
                for(int deltacol=-1;deltacol<=1;deltacol++){
                    int newrow = row + deltarow;
                    int newcol = col + deltacol;
                    if(newrow>=0 && newrow<n && newcol>=0  &&  newcol<m && grid[newrow][newcol]=='1' && !visited[newrow][newcol]){
                        visited[newrow][newcol] = 1;
                        q.push({newrow,newcol});
                    }
                }
            }
        }
        
    }
    
    
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        int count = 0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(i,j, visited, grid);
                    
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends