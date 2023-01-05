class Solution {
public:
    // similar to activity selection problem we sort on the basis of end time
    static bool cmp (vector<int> &a , vector<int> &b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n= intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        int ans = 1;
        int end = intervals[0][1];
        for(int i =1;i<n;i++){
            if(end<=intervals[i][0]){
                ans++;
                end = intervals[i][1];
            }
        }
        return n- ans;
    }
};