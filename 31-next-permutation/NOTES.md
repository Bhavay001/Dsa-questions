STEP 1 :
1) find the index while traversing from the last where nums[i]<nums[i+1]
2) break
3) if we do not find any index and reach  i<0 it means that it is the last permutation
4) so we reverse full array in this case so we reach the first permutation
STEP 2 :
1) we find the the first element while traversing from the last which is greater than the
ith index
we break when we find that element
​
STEP 3 :
1) we swap nums[i], nums[j]
​
STEP 4:
then we reverse(nums.begin() + i+1,nums.end());