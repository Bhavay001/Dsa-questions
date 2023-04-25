class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        unordered_set<int> st;
        for(int i =0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        // we try to count length only when we have found the starting point of the increasing sequence 
        //if we calculate at every number it will be same as the brute force
        int maxlen = 1;
        for(auto x:st){
            if(st.find(x-1) == st.end()){
                int len = 1;
                int num = x;
                while(st.find(num+1)!=st.end()){
                    num++;
                    len++;
                }
                maxlen = max(maxlen,len);
            }
        }
        return  maxlen;
    }
};