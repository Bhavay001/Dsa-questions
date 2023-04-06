class Solution {
public:
    
    bool solve(int row,int col, int wordindex,int n ,int m , string word, vector<int> &dx, vector<int> &dy,vector<vector<char>>& board, vector<vector<int>> &visited){
        if(wordindex ==word.size()){
            return true;
        }
        // out of bound cases
        if(row < 0 || row >=n || col < 0 || col>=m || board[row][col] != word[wordindex] || visited[row][col]){
            return false;
        }
        // visited is because we cannot take an element twice
        visited[row][col] = 1;
        
        for(int i =0;i<4;i++){
            int newrow = row + dx[i];
            int newcol = col + dy[i];
            if(solve(newrow,newcol,wordindex+1,n,m,word,dx,dy,board,visited)){
                return true;
            }
        }
        
        visited[row][col] = 0;
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        vector<int> dx = {0,0,-1,1};
        vector<int> dy = {-1,1,0,0};
        
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(visited[i][j]!=1 && board[i][j] == word[0]){
                    bool res =  solve(i,j,0,n,m,word,dx,dy,board,visited);
                    if(res){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};