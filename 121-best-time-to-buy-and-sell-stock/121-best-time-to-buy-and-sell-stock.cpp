class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> st;
        vector<int> ans;
        for(int i =prices.size()-1;i>=0;i--){
            if(st.empty()){
                ans.push_back(-1);
                st.push(prices[i]);
            }
            else{
                while(!st.empty() && st.top()<=prices[i]){
                    st.pop();
                }
                if(st.empty()){
                    st.push(prices[i]);
                    ans.push_back(-1);
                }
                else if(st.top()>prices[i]){
                    ans.push_back(st.top());
                }
            }
        }
        
        reverse(ans.begin(), ans.end());
        int maxans = 0;
        for(int i =0;i<ans.size();i++){
            if(ans[i]!=-1){
                maxans = max(maxans, ans[i] - prices[i]);
            }
        }
        return maxans;
    }
};