class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int x = 0;
        int y = m-1;
        int sum = 0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(i==j){
                    sum += mat[i][j];
                }
                else{
                    if(i == x && j == y && x<=n-1 && y>=0){
                        sum += mat[x][y];
                        x++;
                        y--;
                        if(x == y){
                            x++;
                            y--;
                        }
                    }
                }
            }
        }
        
        return sum;
            
    }
};