class Solution {
public:
    bool solve(char ch){
        if(ch == 'a' || ch =='e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        // sliding window 
        int i =0;
        int j =0;
        int ans = 0;
        int count = 0;
        
        while(j<s.size()){
            if(solve(s[j])){
                count++;
            }   
            if(j-i+1<k){
                j++;
            }
            
            else if(j-i+1==k){
                ans = max(count,ans);
             
                if(solve(s[i])){
                    count--;
                }

                i++;
                j++;
            }
        }
        return ans;
    }
    
};