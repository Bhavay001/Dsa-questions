class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        int maxtime = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            maxtime = max(time,maxtime);
            
            q.pop();
            for(int i =0;i<4;i++){
                int newrow = row + dx[i];
                int newcol = col + dy[i];
                
                if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && grid[newrow][newcol]==1){
                    grid[newrow][newcol] = 2;
                    q.push({{newrow,newcol},time+1});
                }
            }
        }
        
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        return maxtime;
    }
};