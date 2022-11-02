class Solution {
public:
    
    bool isValid(int row,int col, char c,vector<vector<char>>& board){
        
        for(int i =0;i<9;i++){
            // checking in a row
            if(board[row][i] == c){
                return false;
            }
            
            // checking in a col
            if(board[i][col] == c){
                return false;
            }
            
            // have to check in entire 3 X 3 martrix
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c){
                return false;
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board){
        
        // traverse the matrix
        for(int i =0;i<board.size();i++){
            for(int j =0; j<board[0].size();j++){
                // if the position is empty
                if(board[i][j] == '.'){
                    // if it is empty we traverse from 1-9 and see which of the following is valid for that place
                    for(char c = '1'; c<='9'; c++){
                            if(isValid(i,j,c,board)){
                                board[i][j] = c;

                            // ab aage ki positions bharni hai to  hame solve function call karna hoga aur jb true aajaye                                   return true
                            if(solve(board)== true){
                                return true;
                            }
                            // if it is false we backtrack and make board[i][j] empty

                            else{
                                board[i][j] = '.';   
                            }
                        }
                    }
                    // when we are not able to fill anything from 1-9 if empty place we return false
                    return false;
                }
                // we come here when we do not get an empty space we do not return anything true or false
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};