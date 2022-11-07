class Solution {
    private:
    void dfs(int row,int col,vector<vector<int>>& image,int color,int num,vector<int>&dx,vector<int>&dy){
        image[row][col]= color;
        int n = image.size();
        int m = image[0].size();
        for(int i =0;i<4;i++){
            int newrow = row + dx[i];
            int newcol = col + dy[i];
            if(newrow>=0 && newrow<n && newcol>=0&& newcol < m && image[newrow][newcol] == num){
                dfs(newrow,newcol,image,color,num,dx,dy);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // int n = image.size();
        // int m = image[0].size();
        if(image[sr][sc] == color){
            return image;
        }
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        int num = image[sr][sc];
        dfs(sr,sc,image,color,num,dx,dy);
        return image;
    }
};