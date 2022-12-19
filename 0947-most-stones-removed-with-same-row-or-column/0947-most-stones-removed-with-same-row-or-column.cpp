class DisjointSet{
    public:
    vector<int> parent,rank;
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    
    int findPar(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }
    
    void UnionByRank(int u,int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        
        if(ulp_u==ulp_v){
            return;
        }
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
        
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        // we will make dijoint set first 1 to n for rows then next for columns
        int maxRow = 0;
        int maxCol = 0;
        for(auto x:stones){
            maxRow = max(maxRow,x[0]);
            maxCol = max(maxCol,x[1]);
        }
        
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int,int> stoneNodes;
        // we union the row and column in which the stone is present
        // we also use map so that we ccan traverse on all the rows and col visited and not an empty row 
        for(auto x:stones){
            int Rowno = x[0];
            int Colno = x[1] + maxRow + 1;
            ds.UnionByRank(Rowno,Colno);
            stoneNodes[Rowno] = 1;
            stoneNodes[Colno] = 1;
            
        }
        int cnt = 0;
        for(auto x:stoneNodes){
            int node = x.first;
            if(ds.findPar(node)==node){
                cnt++;
            }
        }
        return n -cnt;
        
    }
};