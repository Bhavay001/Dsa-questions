//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

static bool cmp(Item &a,Item &b){
    double c1 = (double)a.value/a.weight;
    double c2 = (double)b.value/b.weight;
    
    return c1>c2;
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
         sort(arr, arr + n,cmp); 
         
         int i = 0;
         double ans = 0;
         for(int i =0;i<n;i++) {
             if(W>=arr[i].weight){
                 ans += arr[i].value;
                 W = W - arr[i].weight;
             }
             else{
                 double c1 = (double)arr[i].value/arr[i].weight;
                 ans += W *c1;
                 break;
             }
         }
         return ans;
    }
        
};



//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends