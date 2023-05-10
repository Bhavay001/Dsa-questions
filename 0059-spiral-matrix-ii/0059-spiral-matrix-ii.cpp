class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        int num = 1;
        
        vector<vector<int>> ans(n,vector<int>(n,0));
       
        int rowstart = 0;
        int colstart = 0;
        int rowend = n-1;
        int colend = n-1;
        
        int total = n *n;
        int count = 0;
        
        while(count<total){
            
            
            for(int i =colstart;count<total && i<=colend;i++){
                ans[rowstart][i] = num;
                num++;
                count++;
            }
            rowstart++;
            
            for(int i =rowstart;count<total && i<=rowend;i++){
                ans[i][colend] = num;
                num++;
                count++;
            }
            colend--;

            for(int i =colend;count<total && i>=colstart;i--){
                ans[rowend][i] = num;
                num++;
                count++;
            }
            rowend--;

            for(int i =rowend;count<total && i>=rowstart;i--){
                ans[i][colstart] = num;
                num++;
                count++;
            }
            colstart++;
        }
        return ans;
    }
    
};