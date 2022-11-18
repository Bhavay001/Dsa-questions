class Solution {
public:
    

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] ==1){
            return -1;
        }
        vector<vector<int>> distance(n,vector<int> (m,INT_MAX));
        vector<int> ans;
        
        queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{0,0}});
        distance[0][0] = 0;
        while(!pq.empty()){
            int row = pq.front().second.first;
            int col = pq.front().second.second;
            int dis = pq.front().first;
            
            pq.pop();
            
            for(int deltarow=-1;deltarow<=1;deltarow++){
                for(int deltacol=-1;deltacol<=1;deltacol++){
                    int newrow = row + deltarow;
                    int newcol = col + deltacol;
                    if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && grid[newrow][newcol]==0 && distance[newrow][newcol]> dis + 1){

                        distance[newrow][newcol] = dis + 1;
                        pq.push({dis +1, {newrow,newcol}});
                    }
                }
            }
        }
        if(distance[n-1][m-1]== INT_MAX){
            return -1;
        }
        return distance[n-1][m-1] +1;

    }
};
