class Solution {
public:
    int reverse(int x) {
        long long int sum = 0;
        while(x>0){
            int n = x%10;
            sum = sum*10 + n;
            if(sum>pow(2,31)){
                return 0;
            }
            x = x/10;
        }
        while(x<0){
            int n = x%10;
            sum = sum*10 + n;
            if(sum+pow(2,31)<0){
                return 0;
            }
            x = x/10;
        }
        return (int)sum;
    }
};