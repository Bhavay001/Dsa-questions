class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int s[n] , e[n];
        
        for(int i=0;i<n;i++){
            s[i] = intervals[i][0];
            e[i] = intervals[i][1];
        }
        sort(s,s + n);
        sort(e, e+n);
        
        int i =1;
        int j = 0;
        int interval = 1;
        int maxans = 1;
        while(i<n && j<n){
            if(s[i]<=e[j]){
                interval++;
                i++;
            }
            else{
                interval--;
                j++;
            }
            maxans = max(maxans, interval);
        }
        return maxans;
    }
};