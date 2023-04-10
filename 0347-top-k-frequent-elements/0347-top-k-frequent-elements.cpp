class Solution {
public:
    static bool cmp(pair<int,int> &a,pair<int,int> &b){
        return a.second>b.second;
    }
    vector<int> Sort(map<int,int> &mp,int k){
        vector<pair<int,int>> v;
        
        for(auto x:mp){
            v.push_back(x);
        }
        
        sort(v.begin(),v.end(),cmp);
        
        vector<int> ans;
        for(auto x:v){
            if(k>0){
                ans.push_back(x.first);
                k--;
            }
            else{
                break;
            } 
        }

        return ans;
        
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i =0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        return Sort(mp,k);
    }
};