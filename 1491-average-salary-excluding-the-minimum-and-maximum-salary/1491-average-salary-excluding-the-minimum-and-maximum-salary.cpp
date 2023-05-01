class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        for(int i =0;i<n;i++){
            maxi = max(maxi,salary[i]);
            mini = min(mini,salary[i]);
        }
        
        int sum = 0;
        double count = 0;
        for(int i =0;i<n;i++){
            if(salary[i]!=mini && salary[i]!=maxi){
                sum += salary[i];
                count++;
            }
        }
        double ans = sum/count;
        return ans;
        
    }
};