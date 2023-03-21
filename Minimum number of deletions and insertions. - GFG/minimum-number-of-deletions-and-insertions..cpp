//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	  //heap 
	  //pea
	  //lcs = ea
	  //so we delete length will be s1 length - lcs length (4-2 = 2); (h,p deleted)
	  //insertion length will be s2 length - lcs length (3 -2 = 1) (p inserted)
	  // minOperations = delete + insertion = 2 + 1 = 3
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n = str1.length();
	    int m = str2.length();
	    
	    
	    
	    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	    
	    for(int i =0;i<=n;i++){
	        dp[i][0] = 0;
	    }
	    for(int j =0;j<=m;j++){
	        dp[0][j] = 0;
	    }
	    
	    for(int ind1 = 1;ind1<=n;ind1++){
	        for(int ind2=1 ; ind2<=m;ind2++){
	            // match 
	            if(str1[ind1-1]==str2[ind2-1]){
	                dp[ind1][ind2] = 1+ dp[ind1-1][ind2-1];
	            }
	            else dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
	        }
	    }
	    int length = dp[n][m];
	    
	    int deletion = n - length;
	    int insertion = m - length;
	    return deletion + insertion;
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends