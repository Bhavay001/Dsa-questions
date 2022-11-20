Nomal dijakstra will not work as it is possible there is a shorter path but in more steps than k so if even we stop the loop when it exeeds k but we have stored that distance of the path which was short hence we would not get the path with larger distance but within k specified
​
Steps will not be considered in normal dijaktras if we get smaller distance from somewhere else hence it fails
so we will move based on the number of steps and since steps increase +1 at a time in bfs we will not require a priority_queue
​
we will be using queue
with queue it checks all the path hence the path with larger distance will also be traversed if its steps are less than k