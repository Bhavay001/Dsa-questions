//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void dfs(int row,int col , int n ,int m, vector<vector<char>>& mat){
        mat[row][col] = '$';
        for(int i =0;i<4;i++){
            vector<int> dx = {-1,1,0,0};
            vector<int> dy = {0,0,-1,1};
            
            int newrow = row + dx[i];
            int newcol = col + dy[i];
            
            if(newrow>=0 && newrow <n && newcol>=0 && newcol < m && mat[newrow][newcol] == 'O'){
                dfs(newrow,newcol,n,m,mat);
            }
            
        }
    };
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        for(int j =0;j<m;j++){
            if(mat[0][j] == 'O'){
                dfs(0,j,n,m,mat);
            }
            if(mat[n-1][j] == 'O'){
                dfs(n-1,j,n,m,mat);
            }
        }
        
        for(int i=0;i<n;i++){
            if(mat[i][0] == 'O'){
                dfs(i,0,n,m,mat);
            }
            if(mat[i][m-1] == 'O'){
                dfs(i,m-1,n,m,mat);
            }
        }
        
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(mat[i][j] == '$'){
                    mat[i][j] = 'O';
                }
                else{
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends