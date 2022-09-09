class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[0]!=b[0]){
            return a[0]>b[0];
        }
        else{
            return a[1]<b[1];
        }
    }

    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),cmp);
        int weak=0;
        int curr=INT_MIN;
        for(auto it: properties){
            if(curr>it[1]){
                weak+=1;
            }
            else{
                curr=it[1];
            }
        }
        return weak;
    }
};

