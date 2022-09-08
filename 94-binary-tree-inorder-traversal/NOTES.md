---NOTES FOR MORRIS INORDER TRAVERSAL
----we make curr as root so thwat chamges made are done in curr-----
***TreeNode curr = root;***
step 1 :
-----checking if does left even exists or not-----
****if(curr->left ==NULL)****{
-----we just print the curr------
***cout << curr->val ;***
;---now we move curr to right------
***curr =   curr->right***
}
****else{****
--- now if left is not null we find predeccessor(left of curr)-----
**pre = curr->left**
-----then till right is not null && right of pre is not equal to the curr as it will mean thread has already be made we we will move right
****while(pre->right!=NULL && pre->right!=curr){****
';--**pre = pre ->right**
​
ab agar pre null hogya to hame link karne hai pre ka right = curr se thread ban jayega
thread ban hi gya hai to curr ko left bhi move kardengai
****if(pre->right==NULL){****
**pre->right = curr;**
**curr = curr->left**
**}**
**else{**
Ab agar thread hai to delete karna padhega means
​
**pre->right = NULL**
ab iska matlab ye bhi hua ki left subtree pura ho chuka hai to root ko print karke right siubtree mai nikaldengai
**cout<< curr->val;**
bas ab right move karlengai
**curr = curr->right;**
}
}