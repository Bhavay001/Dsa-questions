class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> ans;
        stack<int> st;
        
        ans.push_back(-1);
        st.push(nums2[n-1]);
        
        for(int i = n-2;i>=0;i--){
            if(nums2[i]>=st.top()){
                while(!st.empty() && nums2[i]>=st.top()){
                    st.pop();
                }
                if(st.empty()){
                    ans.push_back(-1);
                    st.push(nums2[i]);
                }
                else{
                    ans.push_back(st.top());
                    st.push(nums2[i]);
                }
            }
            else{
                ans.push_back(st.top());
                st.push(nums2[i]);
            }
        }
        
        reverse(ans.begin(),ans.end());
        
        unordered_map<int,int>mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]] = i;
        }
        
        vector<int> finalans;
        for(int i =0;i<nums1.size();i++ ){
            auto it = mp.find(nums1[i]);
            finalans.push_back(ans[it->second]);
        }
        
        return finalans;
    }
};