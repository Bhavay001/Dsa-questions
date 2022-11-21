//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    int findPosition(int N , int M , int K) {
        // code here
        if(N==1){
            return 1;
        }
        while(M+K>N){
            M = M - N;
        }
        int ans = K + M - 1;
        if(ans == 0){
            return N;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M,K;
        
        cin>>N>>M>>K;

        Solution ob;
        cout << ob.findPosition(N,M,K) << endl;
    }
    return 0;
}
// } Driver Code Ends