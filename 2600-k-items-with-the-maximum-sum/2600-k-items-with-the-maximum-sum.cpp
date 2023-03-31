class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int sum = 0;
        if(k<=numOnes + numZeros){
            if(k<=numOnes){
                sum = k;
            }
            else{
                sum = numOnes;
            }
        }
        else{
            sum = numOnes;
            k = k - numOnes - numZeros;
            if(k<=numNegOnes){
                sum -= k;
            }
            else{
                sum -= numNegOnes;
            }
        }
        return sum;
    }
};