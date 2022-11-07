class Solution {
public:
    int reverse(int num){
        int ans = 0;
        while(num){
            int n = num%10;
            ans = ans * 10 + n;
            num = num/10;
        }
        return ans;
    }
    int maximum69Number (int num) {
        int num1 = reverse(num);
        bool flag = false;
        int ans = 0;
        while(num1){
            if(num1%10 == 6 && !flag){
                ans = ans * 10 + 9;
                num1 = num1/10;
                flag = true;
                continue;
            }
            int n = num1 % 10;
            ans = ans * 10 + n;
            num1 = num1/10;
        }
        return ans;
    }
};