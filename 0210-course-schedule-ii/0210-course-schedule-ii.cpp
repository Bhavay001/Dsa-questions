class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n =numCourses ;
        
        vector<int> adj[n];
        for(int i =0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> indegree(n,0);
        vector<int> ans;
        vector<int> ans1;
        for(int i =0;i<n;i++){
            for(auto x:adj[i]){
                indegree[x]++;
            }
        }
        queue<int> q;
        for(int i =0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int front =q.front();
            q.pop();
            ans.push_back(front);
            for(auto x:adj[front]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }
        if(ans.size()==n){
            return ans;
        }
        else{
            return ans1;
        }
    }
};