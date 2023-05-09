class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int rowstart = 0;
        int colstart = 0;
        int rowend = n-1;
        int colend = m-1;
        
        // since we need to stop when all elements are printed we maintain a count variable
        int count = 0;
        int total = n*m;
        vector<int> ans;
        
        while(count<total){
            
            //pring Starting Row
            for(int i = colstart;count<total && i<=colend;i++){
                ans.push_back(matrix[rowstart][i]);
                count++;
            }
            rowstart++;

            //print Ending Col
            for(int i = rowstart;count<total && i<=rowend;i++){
                ans.push_back(matrix[i][colend]);
                count++;
            }
            colend--;
            
            //print Ending Row
            for(int i = colend;count<total && i>=colstart;i--){
                ans.push_back(matrix[rowend][i]);
                count++;
            }
            rowend--;

            //print Starting Col
            for(int i = rowend;count<total && i>=rowstart;i--){
                ans.push_back(matrix[i][colstart]);
                count++;
            }
            colstart++;
        }
        return ans;
    }
};