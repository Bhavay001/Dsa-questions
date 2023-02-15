class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {

    int carry = 0;
    reverse(num.begin(),num.end());
    for(int i=0;i<num.size();i++){
        if(k>0 || carry !=0){
            int digit = k%10;
            k = k/10;
            int sum = num[i] + digit + carry;
            if(sum>9){
                carry = 1;
                num[i] = sum%10;
            }
            else{
                carry = 0;
                num[i] = sum;
            }
        }  
    }
        if(carry!=0 || k !=0){
            int nums = carry + k;
            while(nums>0){
                int rem = nums%10;
                num.push_back(rem);
                nums = nums/10;
            }
            
            carry = 0;
        }
        reverse(num.begin(),num.end());
        return num;
    }

};