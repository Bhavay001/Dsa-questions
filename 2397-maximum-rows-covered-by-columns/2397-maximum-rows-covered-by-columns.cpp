class Solution {
public:
    void pickColumn(vector<vector<int>>& mat, int cols,int index, int currentCols, vector<int> &visited, int &ans){
        // base case
        // if index has reached till the column end 
        if(index == mat[0].size()){
            
            int count = 0;
            for(int i =0;i<mat.size();i++){
                bool flag = true;
                for(int j =0;j<mat[0].size();j++){
                    // agar mat[i][j] == 1 aur visited nahi hai to ye row possible bahi hai 
                    if(mat[i][j]==1){
                        if(visited[j]==0){
                            flag = false;
                        }
                    }
                }
                if(flag){
                    count++;
                }
            }
            ans = max(count, ans);
            return;
        }
        if(cols>currentCols){
            // pick the columns
            visited[index] =1;
            pickColumn(mat , cols, index+1, currentCols + 1,visited,ans);
            // backtracking
            visited[index] = 0;
            
        }

        // not pick the column
        pickColumn(mat, cols ,index+1, currentCols,visited,ans);
    }
    int maximumRows(vector<vector<int>>& mat, int cols) {
        
        int currentCols = 0;
        vector<int> visited(mat[0].size(),0);
        int ans = 0;
        pickColumn(mat , cols, 0, currentCols, visited, ans);
        return ans;
    }
};