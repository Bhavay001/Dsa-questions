class Solution {
public:
    // bfs
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image[sr][sc] == color){
            return image;
        }
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int prevcolor  = image[sr][sc];
        image[sr][sc] = color;
        int n = image.size();
        int m = image[0].size();
        
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i =0;i<4;i++){
                int newrow = row + dx[i];
                int newcol = col + dy[i];
                
                if(newrow>=0 && newrow <n && newcol>=0 && newcol<m && image[newrow][newcol] == prevcolor ) {
                    image[newrow][newcol] = color;
                    q.push({newrow,newcol});
                }
            }
        }
        return image;
    }
};