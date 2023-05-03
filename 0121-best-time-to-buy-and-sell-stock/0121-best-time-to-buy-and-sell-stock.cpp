class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> maxprofit;
        int n = prices.size();
        int maxi = 0;
         int ans = 0;
        for(int i = n-1;i>=0;i--){
            maxi = max(maxi,prices[i]);
            ans = max(maxi - prices[i],ans);  
        
        }
        
      
        return ans;
    }
};