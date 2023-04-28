class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // i will store the next smaller and previous smaller index
        
        // we store the next smaller in an vector
        int n = heights.size();
        stack<pair<int,int>> st1;
        vector<int> nse;
        st1.push({heights[n-1],n-1});
        nse.push_back(n);
        for(int i = n-2;i>=0;i--){
            if(st1.top().first>=heights[i]){
                while(!st1.empty() && st1.top().first>=heights[i]){
                    st1.pop();
                }
                if(!st1.empty()){
                    nse.push_back(st1.top().second);
                    st1.push({heights[i],i});
                }
                else{
                    st1.push({heights[i],i});
                    nse.push_back(n);
                }
            }
            else{
                 nse.push_back(st1.top().second);
                 st1.push({heights[i],i});
            }
        }
        reverse(nse.begin(),nse.end());
        
        // we store previous smaller in a vector
        stack<pair<int,int>> st2;
        vector<int> pse;
        st2.push({heights[0],0});
        pse.push_back(-1);
        for(int i = 1;i<n;i++){
            
            if(st2.top().first>=heights[i]){
                while(!st2.empty() && st2.top().first>=heights[i]){
                    st2.pop();
                }
                if(!st2.empty()){
                    pse.push_back(st2.top().second);
                    st2.push({heights[i],i});
                }
                else{
                    st2.push({heights[i],i});
                    pse.push_back(-1);
                }
            }
            else{
                 pse.push_back(st2.top().second);
                 st2.push({heights[i],i});
            }
        }
        
        // now i find the maximum among all rectangular area
        int maxi = 0;
        for(int i = 0;i<n;i++){
            int ans = heights[i] * (nse[i] - pse[i] - 1);
            maxi = max(maxi,ans);
        }
        return maxi;
    }
};