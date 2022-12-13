class DisjointSet{
    vector<int> parent,rank;
    public:
    DisjointSet(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    ds.UnionByRank(i,j);
                }
            }
        }
        // now we check each node if we get a node whose parent is himselt it means we can add
        int count = 0;
        for(int i =0;i<n;i++){
            if(ds.findPar(i)==i){
                count++;
            }
        }
        return count;
    }
};