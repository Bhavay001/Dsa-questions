class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        // we will search for the first element that is greater or equal to the target by binary search and then 
        //from that index we can calculate the elements on the left will not be successful pairs
        sort(potions.begin(),potions.end());
        
        for(int i =0;i<spells.size();i++){
            int s = 0;
            int e = potions.size()-1;
            int ind = potions.size();
            while(s<=e){
                int mid = s + (e-s)/2;

                if((long long int)spells[i] * (long long int)potions[mid]>= success){
                    e = mid - 1;
                    ind = mid;
                }
                else{
                    s = mid + 1;
                }
            }
            int elements = potions.size()-ind;
            ans.push_back(elements);
        }
        return ans;
    }
};