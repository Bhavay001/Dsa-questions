class Solution {
public:
    int sumdigits(int ans){
        int sum = 0;
        while(ans>0){
            int num = ans%10;
            sum += num;
            ans = ans/10;
        }
        return sum;
    }
    int addDigits(int num) {
        int ans = num;
        while(ans>9){
            ans = sumdigits(ans);
        }
        return ans;
    }
};