class Solution {
public:

    // bottom- up space optimized
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        
        int prev2 = cost[0];
        int prev= cost[1];
        
        for(int i=2;i<n;i++){
            int left = prev + cost[i];
            int right = prev2 + cost[i];
            int curr = min(left,right);
            prev2 = prev;
            prev = curr;
        }

        
        // beacause we can start from 0 step as well as 1st step
        return min(prev,prev2);
    }
};