//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S[] = read.readLine().split(" ");
            Long A = Long.parseLong(S[0]);
            Long B = Long.parseLong(S[1]);

            Solution ob = new Solution();
            Long[] ptr = ob.lcmAndGcd(A,B);
            
            System.out.print(ptr[0]);
            System.out.print(" ");
            System.out.println(ptr[1]);
        }
    }
}
// } Driver Code Ends


class Solution {
    public static Long gcd(Long a,Long b){
        if(a==0){
            return b;
        }
        if(b==0){
            return a;
        }
        
        return gcd(b%a,a);
    } 
    static Long[] lcmAndGcd(Long A , Long B) {
        // code here
        // lcm * gcd = a*b
        Long[] arr = new Long[2];
        Long ans = gcd(A,B);
        arr[1] = ans;
        Long Lcm =((A*B)/ans);
        arr[0] = Lcm;
        return arr;
    }
};