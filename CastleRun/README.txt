
https://practice.geeksforgeeks.org/problems/castle-run/0


Castle RUN Submissions: 1110   Accuracy: 11.36%   Difficulty: Medium
     
Mayank once came to New Delhi for an International Mathematics Conference. His mathematics skills were a great topic of discussion in those days. So a mathematician Harsh “Challenged” Mayank for a competition and Mayank accepted it.

Rules: They will ask 3 questions each and the one who will give all the answers right will be the winner.
Mayank answered all the questions very easily. Now its time for Harsh to answer the questions but Harsh was confused by the very first question now you have to help so let's read the question.

Question: Mayank asked that you are in a beautiful Castle which is huge and contains ’N’ number of rooms and each room contains 'M' path to ‘M’ other rooms. There may be only one path which connects two room i.e either one path or no path. Mayank asked that you have to find whether you can reach back to the room from which you started after travelling all the paths but note that once you travel a path, then it will be closed and make sure all the rooms are travelled atleast once. In general all paths are to be travelled exactly once and each room must be travelled atleast once. Note: If any room is not connected print False and if there is only one room then print True.

Input:
The first line will contain an integer T(number of test cases). Each test case will contain an Integer ’N’ i.e.number of rooms and next ’N’ lines will contain ’N’ integers each stating whether there is a path between room ni & nj.

Note: If no path exists then the value is -1, if the room is same then the value will be 0 and if a path exists the value will be 1. Path between room ni & nj is both ways.

Output:
For each test case, print "True" if you can reach back else print "False".

Constraints:
1<=T<=100
1<=N<=10000

Example:
Input
1
5
0 1 1 1 1
1 0 -1 1 -1
1 -1 0 1 -1
1 1 1 0 1
1 -1 -1 1 0
Output
True

Explanation:
There can be a path from r1->r3->r4->r5->r1->r4->r2->r1 where r1,r2,r3,r4,r5 are rooms. Here all paths are covered and r1 is reached again.

This is an undirected graph - solution is to determine whether each vertex has an even degree.  If so, the output is true. Otherwise, false.
 