class Solution {
public:

    void solve(int index, vector<int> &candidates, int target, vector<vector<int>>& finalans, vector<int> &ans){
        // agar target 0 hai matlab ek set of combination mil gya
        if(target == 0){
            finalans.push_back(ans);
            return;
        }
        
        // loop kro index se end tak aur 

        for(int i = index; i<candidates.size();i++){
            ///1) agar current element target se hi bada ho to break
            if(candidates[i]>target){
                break;
            }
            //2) ek to first occurance leni hao to i>index 
            // aur agar element previous kai hi equal hai to we  have to move forward
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
            }
            ans.push_back(candidates[i]);
            solve(i+1,candidates,target-candidates[i],finalans, ans);
            ans.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> finalans;
        vector<int> ans;
        int index = 0;
        sort(candidates.begin(),candidates.end());
        solve(index, candidates, target, finalans, ans);
        return finalans;
    }
};