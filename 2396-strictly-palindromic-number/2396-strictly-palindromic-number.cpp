class Solution {
public:
    bool checkpalindrome(vector<int> binarynum){
        int i =0;
        int j = binarynum.size()-1;
        while(i<j){
            if(binarynum[i]==binarynum[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool isStrictlyPalindromic(int n) {

        vector<int>binarynum;

        for(int i =2;i<=n-2;i++){
            int ans = n;
            while (ans > 0) {
                binarynum.push_back(ans % i);
                ans = ans / i;
            }
            
            if(!checkpalindrome(binarynum)){
                return false;
            }

            else{
                binarynum.clear();
            }
        }
        
        return true;
   
    }
};