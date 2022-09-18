1. dummy node does not point anywhere to the answer node
we can assume a node of 0 value which is there to  access the head of the newly made linked list thats why we return dummy ->next;
2.  *carry = sum/10* as if sum is a single digit carry will automatically become zero
for eg  sum = 12;
carry will be 12/ 10 = 1;
3. **ListNode * node  = new ListNode(sum%10);**
here we add new node which is sum %10
for eg sum = 12;
12 % 10 = 2
so in the new node we add the digit 2;