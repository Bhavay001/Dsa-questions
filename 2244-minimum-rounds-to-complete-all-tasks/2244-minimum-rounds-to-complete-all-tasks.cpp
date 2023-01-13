class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(int i =0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        
        for(auto x:mp){
            if(x.second<2){
                return -1;
            } 
        }
        int ans = 0;
        for(auto x:mp){
            int num = x.second;
            if(num %3 ==0){
                ans += (num/3);
            }
            else{
                while(num>4){
                   num = num -3;
                   ans += 1;
                }
                if(num == 4){
                    ans += 2;
                }
                else{
                    ans += 1;
                }
            }
        }
        return ans;
    }
};