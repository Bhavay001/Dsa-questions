class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // vector of visited nbna diya jismai sab 1 hain 
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(n, vector<int>(m,0));
        
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        
        // ab saare elements in grid jo 2 hain yaani rotten  use ham queue mai push kra dengai with time 0
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]== 2){
                    q.push({{i,j},0});
                    visited[i][j] = 2; 
                }
            }
            
        }
        // ab jabtak q empty nhi hoti ham adjacent visit karte jayengai time badhta jayega 
        // jo maximum time aayega wohi hamara answer hai as we are doing bfs
        int maxtime = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            maxtime = max(maxtime,time);
            q.pop();
            
            for(int i = 0;i<4;i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if(nrow>=0 && nrow< n && ncol >= 0 && ncol < m && grid[nrow][ncol] ==1 && visited[nrow][ncol] ==0){
                    q.push({{nrow,ncol},time+1});
                    visited[nrow][ncol] = 2;
                }
            }
        }
        // last mai check karliya agar aise elements hain to grid mai 1 hain aur visited mai rotten 2 nhi hue to
        // alll oranges are not rottened return -1
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]== 1 && visited[i][j] == 0){
                    return -1;
                }
            }
        }
        return maxtime;
    }
};