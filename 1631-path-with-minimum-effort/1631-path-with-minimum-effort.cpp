class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        
        //{diff,{row,col}}
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({0,{0,0}});
        vector<vector<int>> distance(n,vector<int> (m,INT_MAX));
        distance[0][0] = 0;
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        
        // we will use dijkstra.s algorithm 
        while(!pq.empty()){
            
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int diff = pq.top().first;
            pq.pop();
            
            for(int i =0;i<4;i++){
                int newrow = row + dx[i];
                int newcol = col + dy[i];
                
                // we check if the distance of new node is greater than maximum of  the (absolute difference between the the
                // adjacent elements or the differece stored) before in the priority queue
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && distance[newrow][newcol]>max(abs(heights[row][col] - heights[newrow][newcol]),diff)){
                    distance[newrow][newcol] = max(abs(heights[row][col] - heights[newrow][newcol]),diff);
                    pq.push({distance[newrow][newcol],{newrow,newcol}});
                }
            }
            
        }
        // here the minimum absolute path would have been stored
        return distance[n-1][m-1];
    }
};