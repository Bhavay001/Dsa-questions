class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // space optimization
        vector<int> prev(n,0);
        
        for(int i =0;i<m;i++){
            vector<int> temp(n,0);
            for(int j =0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    temp[j] = 0;;
                }
                else if(i==0 && j==0){
                    temp[j] = 1;
                }
                else{
                    int left = 0;
                    int up = 0;
                    if(i>0){
                        left = prev[j];
                    }
                    if(j>0){
                        up = temp[j-1];
                    } 
                    temp[j] = left+up;
                }
            }
            prev = temp;

        }
        return prev[n-1];
    }
};