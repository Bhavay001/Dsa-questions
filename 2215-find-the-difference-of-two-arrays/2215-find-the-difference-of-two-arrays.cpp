class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        map<int,bool> mp1;
        map<int,bool> mp2;
        int n = nums1.size();
        int m = nums2.size();
        
        for(int i =0;i<n;i++){
            mp1[nums1[i]] = true;
        }
        for(int i =0;i<m;i++){
            if(mp1.find(nums2[i])!=mp1.end()){
                mp1[nums2[i]] = false;
            }
        }
        vector<int> v;
        for(auto x:mp1){
            if(x.second==true){
                v.push_back(x.first);
            }
        }
        ans.push_back(v);
        
        for(int i =0;i<m;i++){
            mp2[nums2[i]] = true;
        }
        for(int i =0;i<n;i++){
            if(mp2.find(nums1[i])!=mp2.end()){
                mp2[nums1[i]] = false;
            }
        }
        vector<int> v1;
        for(auto x:mp2){
            if(x.second==true){
                v1.push_back(x.first);
            }
        }
        ans.push_back(v1);
        return ans;
    }
};