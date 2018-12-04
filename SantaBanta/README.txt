https://practice.geeksforgeeks.org/problems/santa-banta/0/?ref=self

Santa Banta
Submissions: 1291 ? Accuracy: 5.27% ? Difficulty: Medium ? Marks: 4
       

Santa is still not married. He approaches a marriage bureau and ask them to hurry the process.
The bureau checks the list of eligible girls (n) and hands it over to Santa.
Santa being conscious about his marriage, determined to find a girl with maximum connections so that he can gather more information about her.
Accordingly, he looks to figure out the maximum number of girls (from list) who know each other to achieve above purpose.
In order to finalise the girl,he needs to find the Kth prime.
Where k = largest group of girls who know each other .
Considering Santa's poor knowledge in Maths, he seeks for Banta's help for the answer.
Now you , being fan of Santa Banta Jokes, take this prestigious opportunity to solve the problem.

In case no of connections are zero ,print "-1".

Note :
Suppose girl "a" knows girl "b" and girl "b" knows girl "c" , then girl "a" also knows girl "c".
Transitivity holds.
Consider 1 composite no.

Input:
First line of the input contains t, the number of test cases. Each line of the test case contains a number n specifying the number of girls and m specifying no of connections. Each 'm' lines contain u and v denoting that girl u and v know each other.

Output:
Each new line of the output contains Kth prime no .

Constraints:

1<=t<=205
1<=n<=100000
0<=m<=10000
1<=u,v<=n

Example:

Sample Input 0

1
10 6
1 2
2 3
3 4
4 5
6 7
9 10

Sample Output 0

11