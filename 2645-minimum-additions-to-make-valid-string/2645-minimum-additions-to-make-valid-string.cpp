class Solution {
public:
    int addMinimum(string word) {
        int n = word.size();
        int i = 0;
        int res = 0;
        while(i<n){
            int count = 0;
            if(i<n && word[i]=='a'){
                i++;
                count++;
            }
            if(i<n && word[i]=='b'){
                i++;
                count++;
            }
            if(i<n && word[i]=='c'){
                i++;
                count++;
            }
            res += 3-count;
        }
        
        return res;
    }
};