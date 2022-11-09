class Solution {
public:
    void dfs(int row,int col ,vector<vector<int>>& visited, vector<vector<char>>& board, vector<int> dx, vector<int> dy){
        
        int n = board.size();
        int m = board[0].size();
        
        visited[row][col] = 1;
        
        for(int i =0;i<4;i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && board[nrow][ncol] == 'O'){
                dfs(nrow,ncol,visited,board,dx,dy);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        //I check the boundry and if there is a O i call the dfs on all O connected with it as the cannot be surrounded by X
        // top row
        
        // in this question i have to change "O" to "X" wwhich are surrounded by X
        // so the "O" which are the the boundry and its neighbouring "O" cannot be changed

        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        for(int j = 0;j<m;j++){
            if(!visited[0][j] && board[0][j]=='O'){
                dfs(0,j,visited,board,dx,dy);
            }
            
            if(!visited[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1,j,visited, board,dx,dy);
            }
        }
        
        for(int i = 0;i<n;i++){
            if(!visited[i][0] && board[i][0]=='O'){
                dfs(i,0,visited,board,dx,dy);
            }
            
            if(!visited[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,visited, board,dx,dy);
            }
        }
        
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(!visited[i][j] && board[i][j] == 'O'){
                   board[i][j] = 'X'; 
                }
            }
        }
    }
};