class Solution {
public:
    
    bool isSafe(int row, int col , vector<string> & board, int n){
        int duprow = row;
        int dupcol = col;
        
        // checking backward upwards
        while(row>= 0 && col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col--;
        }
        
        row = duprow;
        col = dupcol;
        
        // checking backwards
        while(col>=0){
            if(board[row][col] == 'Q'){
                return false;
            }
            col--;
        }
        
        row = duprow;
        col = dupcol;
        
        // checking backward downwards
        
        while(row< n && col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row++;
            col--;
        }
        
        return true;   
    }
    
    void solve(int col, vector<string> &board, vector<vector<string>> &ans,  vector<int> &leftRow,vector<int> &upperDiagonal,vector<int> &lowerDiagonal, int n){
        
        // base case when we have aput queen in every column
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row<n; row++){
            if(leftRow[row] == 0 && upperDiagonal[row + col] == 0 && lowerDiagonal[n-1 + col - row] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                upperDiagonal[row + col] = 1;
                lowerDiagonal[n-1 + col - row] = 1;
                solve(col +1, board , ans ,leftRow,upperDiagonal,lowerDiagonal, n);
                
                // while backtracking
                board[row][col] = '.';
                leftRow[row] = 0;
                upperDiagonal[row + col] = 0;
                lowerDiagonal[n-1 + col - row] = 0;
            }
        }
        
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; // stores final ans
        vector<string> board(n);  // stores answer for that particular recursion call
        string s(n,'.'); // creates a string with all (.)
        
        // now initializing board string matrix with (.)
        for(int i =0 ;i<n;i++){
            board[i] = s;
        }
        vector<int> leftRow(n,0) , upperDiagonal(2*n-1,0) , lowerDiagonal(2*n-1,0);
        solve(0, board , ans ,leftRow,upperDiagonal,lowerDiagonal, n);
        return ans;
    }
};