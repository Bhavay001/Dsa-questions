class Solution {
public:
    
    void solve(int index, vector<int> &candidate, int target, vector<vector<int>> &finalans, vector<int> &ans){
        //base case
        // reached end
        if(candidate.size()== index){
            if(target==0){
                finalans.push_back(ans);
            }
            return;
        }
        
        // in this question we can take an element multiple times so when TAKE/INCLUDE i will not increase the 
        //indeX decrease the target value ans push element in ans vector till target is >= arr[i]
        if(target >= candidate[index]){
            // take
            ans.push_back(candidate[index]);
            solve(index,candidate, target-candidate[index], finalans, ans);
            // if we icluded while returning i have to pop that included element
            ans.pop_back();
        }
        
        // exclude
        // when i exclude i move the index forward but as i have excluded target will be te same
        solve(index+1, candidate, target, finalans, ans);
    }
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> finalans;
        vector<int> ans;
        int index = 0;
        solve(index, candidates, target, finalans, ans);
        return finalans;
    }
};