class Solution {
public:
    
    // without recursion 
    // if we wanted to do it with recursion we would have found all the permutations of the numbers then we would have stored them in a data structure then we could have found the kth permutation in it 
    
    // non recursive solution
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;
        for(int i =1;i<n;i++){
            fact = fact * i; // 123 3! 6 as 1 as 1 number will be fixed
            numbers.push_back(i); // 1 2 3
        }
        numbers.push_back(n); // 1 2 3 4
        string ans = "";
        k = k-1; // 0 based indexing
        while(true){
            // here we add the 
            ans += to_string(numbers[k/fact]);
            numbers.erase(numbers.begin() + k/fact);
            if(numbers.size()==0){
                break;
            }
            k = k%fact;
            fact = fact / numbers.size();
        }
        return ans;
    }
};