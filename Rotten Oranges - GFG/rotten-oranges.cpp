//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    void dfs(int time , int i , int j , vector<vector<int>> & grid){
        
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dx {-1,1,0,0};
        vector<int> dy {0,0,-1,1};
            
        queue<pair<pair<int,int>,int>>q;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    grid[i][j] = 3;
                }
            }     
        }
        int maxtime = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            maxtime = max(maxtime,time);
            q.pop();
            

            for(int i =0;i<4;i++){
                int newrow = row + dx[i];
                int newcol = col + dy[i];
                
                if(newrow>=0 && newrow<n && newcol >=0 && newcol <m){
                    if(grid[newrow][newcol]==1){
                        grid[newrow][newcol] = 3;
                        q.push({{newrow,newcol},time +1});
                    }
                }
            }
        }
        
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==1 ){
                    return -1;
                }
            }     
        }
        
        return maxtime;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends