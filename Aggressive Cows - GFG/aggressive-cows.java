//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t;
        t = sc.nextInt();
        while (t-- > 0) {

            int n;
            n = sc.nextInt();

            int k;
            k = sc.nextInt();

            int[] v = new int[n];
            for (int i = 0; i < n; i++) v[i] = sc.nextInt();

            Solution obj = new Solution();
            int res = obj.solve(n, k, v);

            System.out.println(res);
        }
    }
}

// } Driver Code Ends


// User function Template for Java
class Solution {
    public static boolean isPossible(int n,int k,int mid,int []stalls) {
		int prevcow = stalls[0];
		int cowcount = 1;
		
		for(int i =0;i<n;i++) {
			if(stalls[i] - prevcow>=mid) {
				cowcount++;
				prevcow = stalls[i];
				if(cowcount==k) {
					return true;
				}
			}
		}
		return false;
	}

    public static int solve(int n, int k, int[] a) {
		Arrays.sort(a);
		int s = 1;
		int e = a[n-1] - a[0];
		int ans = 0;
		int mid = s + (e-s)/2;
		while(s<=e) {
			if(isPossible(n,k,mid,a)) {
				ans = mid;
				s = mid+1;
			}
			else {
				e = mid -1;
			}
			mid = s + (e-s)/2;
		}
		return ans;
        
    }
}