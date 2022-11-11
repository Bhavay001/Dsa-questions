class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        
        // we need to create the adjacency list we are given a pair of matrix
        vector<int> adj[n];
        for(int i =0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        // this problen shortens to checking if the cycle is present or not as when cycle is present topo sort will
        // not be possible else toposort will be possible 
        vector<int> indegree(n,0);
        for(int i =0;i<n;i++){
            for(auto x:adj[i])
            indegree[x]++;
        }
        queue<int> q;
        for(int i =0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }   
        }
        int cnt = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            cnt++;
            for(auto x:adj[front]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }
        if(cnt==n){
            return true;
        }
        else{
            return false;
        }
    }
};