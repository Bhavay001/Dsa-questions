class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // make a prefix max subarray
        vector<int> prefix(n,0);
        prefix[n-1] = prices[n-1];
        for(int i = n-2;i>=0;i--){
            prefix [i] = max(prefix[i+1],prices[i]);
        }
        int maxi = 0;
        for(int i =0;i<n;i++){
            maxi = max(maxi ,prefix[i] - prices[i]);
        }
        return maxi;
    }
};