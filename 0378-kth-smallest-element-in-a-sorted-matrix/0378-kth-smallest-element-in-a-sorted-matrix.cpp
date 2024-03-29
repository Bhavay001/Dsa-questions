class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // priority queue approach
        int n = matrix.size();
        int m =matrix[0].size();
        
        priority_queue<int> pq;
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(pq.size()<k){
                    pq.push(matrix[i][j]);
                }
                else{
                    if(pq.top()>matrix[i][j]){
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }
            }
        }
        
        return pq.top();
    }
};