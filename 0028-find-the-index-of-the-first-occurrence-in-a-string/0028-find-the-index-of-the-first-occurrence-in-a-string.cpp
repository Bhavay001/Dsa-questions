class Solution {
public:
    //
    int strStr(string haystack, string needle) {
        string s = "";
        int i = 0;
        int j =0;
        int k = needle.size();
        while(j<haystack.size()){
            s +=haystack[j];
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                if(s==needle){
                    return i;
                }
                s.erase(0, 1);
                i++;
                j++;
            }
        }
        return -1;
    }
};