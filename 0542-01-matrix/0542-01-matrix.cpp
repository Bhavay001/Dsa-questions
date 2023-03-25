class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> dis(n,vector<int> (m,0));
        vector<vector<int>> visited(n,vector<int> (m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(mat[i][j] == 0){
                   q.push({{i,j},0});
                    visited[i][j] =1;
                }
            }
        }
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            
            dis[row][col] = dist;
            vector<int> dx = {-1,1,0,0};
            vector<int> dy = {0,0,-1,1};
            
            for(int i =0;i<4;i++){
                int newrow = row + dx[i];
                int newcol = col + dy[i];
                
                if(newrow>=0 && newrow <n && newcol >=0 && newcol <m && !visited[newrow][newcol]){
                    q.push({{newrow,newcol},dist + 1});
                    visited[newrow][newcol] = 1;
                }
            }
            
        }
        return dis;
    }
};