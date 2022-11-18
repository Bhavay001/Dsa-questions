//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
                         
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> distance(n,vector<int>(m,INT_MAX));
        if(source.first==destination.first && source.second==destination.second) 
            return 0;
        
        // {distance , {row,col}}
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        
        q.push({0,{source.first,source.second}});
        distance[source.first][source.second] = 0;
        
        while(!q.empty()){
            int row = q.front().second.first;
            int col = q.front().second.second;
            int dis = q.front().first;
            
            q.pop();
            
            for(int i=0;i<4;i++){
                int newrow = row + dx[i];
                int newcol = col +dy[i];
            
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && grid[newrow][newcol]==1 && dis + 1 <distance[newrow][newcol]){
                    if(destination.first == newrow && destination.second ==newcol){
                        return  dis + 1;
                    }
                    distance[newrow][newcol] = dis + 1;
                    q.push({dis+1,{newrow,newcol}});
                }
                
            }
            
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends