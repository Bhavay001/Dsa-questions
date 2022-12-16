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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string,int> mapMailNode;
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            //  as first string of every array is name
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mapMailNode.find(mail)==mapMailNode.end()){
                    mapMailNode[mail] = i;
                }
                // agar koi element pehle se seen hai to in nodes ko merge karna padhega 
                else{
                   ds.UnionByRank(mapMailNode[mail] , i);
                }       
            }
        }
        // ["John","johnsmith@mail.com","john_newyork@mail.com"],
        //  ["John","johnsmith@mail.com","john00@mail.com"]
        // now in map we just pared the common one the rest remaining in that should also have parent changed

        vector<string> mergedmail[n];
        for(auto x : mapMailNode){
            string mail = x.first;
            int node = ds.findPar(x.second);
            mergedmail[node].push_back(mail);
        }
        
        // node i just need the answer
        vector<vector<string>> ans;
        for(int i = 0;i<n;i++){
            if(mergedmail[i].size() == 0){
                continue;
            }
            sort(mergedmail[i].begin(),mergedmail[i].end());
            
            // we need a neme also
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto x : mergedmail[i]){
                temp.push_back(x);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};