class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int reachable = 0;
        for(int i=0;i<nums.size();i++){
            
            // if index excceds the maximum reachble point we return false;
            if(i>reachable){
                return false;
            }
            int index = i + nums[i];
            reachable = max(index,reachable);
            
            

        }
        if(reachable >= nums.size()-1){
            return true;
        }
        return false;
    }
};