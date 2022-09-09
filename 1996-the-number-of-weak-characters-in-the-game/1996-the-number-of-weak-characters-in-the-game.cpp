class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        // reverse order of attack time if the elements are not equal
        if(a[0]!=b[0]){
           return a[0]>b[0];
        }
        // agar equal hai to second waala chota pehle
        return a[1]<b[1];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        // sorting in reverse order of attack time
        int n = properties.size();
        sort(properties.begin(), properties.end(),cmp);
        int max = INT_MIN;
        int weak = 0;
        for(int i =0;i<n;i++){
            // agar max bada hai current element se to weak hai
            if(max>properties[i][1]){
                weak++;
            }
            else
            // warna max ko update kardo
                max = properties[i][1];
        }
        
        return weak;
    }
};