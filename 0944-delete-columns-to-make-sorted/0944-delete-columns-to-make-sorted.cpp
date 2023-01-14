class Solution {
public:
    bool isValid(char a , char b){
        if(a>b){
            return false;
        }
        return true;
    }
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ans = 0;
        set<int> s;
        unordered_map<int,char> mp;
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mp.find(j)==mp.end()){
                    mp[j] = strs[i][j];
                    
                }
                else if(isValid(mp[j],strs[i][j])){
                    mp[j] = strs[i][j];
                }
                else{
                    s.insert(j);
                }
            }
        }
        return s.size();
    }
};


