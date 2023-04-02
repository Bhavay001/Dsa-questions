class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size();
        if(digits[n-1]<9){
            digits[n-1] = digits[n-1] +1;
            return digits;
        }
        else{
            digits[n-1] = 0;
            int carry = 1;
            int i = n-2;
            while(carry && i>=0){
                if(digits[i]==9){
                    carry = 1;
                    digits[i] = 0;
                    i--;
                }
                else{
                    carry = 0;
                    digits[i] = digits[i] +1;
                }
            }
            if(carry == 1){
                reverse(digits.begin(),digits.end());
                digits.push_back(1);
                reverse(digits.begin(),digits.end());
            }
        }
       return digits;
    }
};