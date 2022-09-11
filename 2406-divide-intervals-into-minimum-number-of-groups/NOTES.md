This question is similar to the question minimum number of  platforms
1) we have to sort the left intervals and the right intervals so we  will make to arrays which will store the left ans right in different arrays and sort them this will not have an impact on our answer
2) now after sorting we maintain 4 things the i pointer j pointer interval wich stores if left interval comes before the right interval has ended and the maximimum intervals among the intervals
3) we check if s[i]<= e[j] (yaani start pehle ho gya) we do interval ++ ans i++
4) else we do interval -- ans j++
5) in each iteration we store maximum of intervals