class Solution {
public:
    
    bool isprime(int num){
        if(num<=1){
            return false;
        }   
        for(int i = 2;i*i<=num;i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int n =nums.size();
        int maxi = 0;
        for(int i =0;i<n;i++){
            if(isprime(nums[i][i])){
                maxi = max(maxi,nums[i][i]);
            }
            if(isprime(nums[i][n-i-1])){
                maxi = max(maxi,nums[i][n-i-1]);
            }
        }
        return maxi;
    }
};