https://practice.geeksforgeeks.org/problems/maximum-tip-calculator/0

Maximum Tip Calculator Submissions: 28710   Accuracy: 16.86%   Difficulty: Medium   Marks: 4
           
Rahul and Ankit are the only two waiters in Royal Restaurant. Today, the restaurant received N orders. The amount of tips may differ when handled by different waiters, if Rahul takes the ith order, he would be tipped Ai rupees and if Ankit takes this order, the tip would be Bi rupees.
In order to maximize the total tip value they decided to distribute the order among themselves. One order will be handled by one person only. Also, due to time constraints Rahul cannot take more than X orders and Ankit cannot take more than Y orders. It is guaranteed that X + Y is greater than or equal to N, which means that all the orders can be handled by either Rahul or Ankit. Find out the maximum possible amount of total tip money after processing all the orders.


Input:

•    The first line contains one integer, number of test cases.
•    The second line contains three integers N, X, Y.
•    The third line contains N integers. The ith integer represents Ai.
•    The fourth line contains N integers. The ith integer represents Bi.

 

Output:
Print a single integer representing the maximum tip money they would receive.
 

Constraints:
1 ≤ N ≤ 105
1 ≤ X, Y ≤ N; X + Y ≥ N
1 ≤ Ai, Bi ≤ 104

 

Example:

Input:

2
5 3 3
1 2 3 4 5
5 4 3 2 1
8 4 4
1 4 3 2 7 5 9 6 
1 2 3 6 5 4 9 8

 

Output:

21
43


---------------------------------

EDITORIAL
In the above problem we will use greedy approach to get the maximum tip earned by the two waiters. Following steps will help in solving this problem:
1.    Sort the absolute difference of the value of Ai and Bi( |Ai-Bi|) in decreasing order.
2.    Compare Ai and Bi value which one will be greater add that value to the sum.
3.    Decrement from the total order taken by Rahul or Ankit in case of order taken from A or B row by the comparison made.
4.    If i equals to n goto step 5 else goto step 2.
5.    Return sum.
 