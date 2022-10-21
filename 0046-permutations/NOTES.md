permutation
APPROACH -1
1)recursive call is made to 1 first it is added in the stack marked visited then the next call will be made till size of vector is less than nums vector
​
2) now when the size of ans is equal to  nums vector we will return
3) then while backtracking we will make freq back to 0 and pop from ans vector
​
APPROACH-2
in this we do not use the extra spaces we used in previous approach we loop through the vector nums and swap INDEX-I  call  recursion on next index and while backtracking remove the changes made by again swapping I ->INDEX
​