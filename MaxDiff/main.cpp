#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node
{
   int data;
   struct Node* left;
   struct Node* right;
};
/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
   struct Node* node = (struct Node*)
      malloc(sizeof(struct Node));
   node->data = data;
   node->left = NULL;
   node->right = NULL;
   return(node);
}
int maxDiff(Node *root);
int main()
{
   /*
   int t;
   struct Node *child;
   scanf_s("%d", &t);
   while (t--)
   {
      map<int, Node*> m;
      int n;
      scanf_s("%d", &n);
      struct Node *root = NULL;

      while (n--)
      {
         Node *parent;
         char lr;
         int n1, n2;
         scanf_s("%d %d %c", &n1, &n2, &lr);
         if (m.find(n1) == m.end())
         {
            parent = newNode(n1);
            m[n1] = parent;
            if (root == NULL)
               root = parent;
         }
         else
            parent = m[n1];
         child = newNode(n2);
         if (lr == 'L')
            parent->left = child;
         else
            parent->right = child;
         m[n2] = child;
      }
      cout << maxDiff(root) << endl;
   }
   */

   Node* root = newNode(100);
   Node* cur = root;
   for (int i = 0; i < 3000; i++) {
      cur->left = newNode(i);
      cur = cur->left;
   }

   maxDiff(root);
   return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node
struct Node
{
int data;
Node* left, * right;
}; */
/* Your are required to
complete this method*/
int maxDiffBruteForce(Node* root);
int maxDiffOther(Node* root);

int maxDiff(Node* root)
{

   int j = maxDiffOther(root);
   int i = maxDiffBruteForce(root);

   return j;
}

int findMin(Node* root, int curMin=INT_MAX)
{
   if (!root)
      return curMin;

   if (root->data < curMin)
      curMin = root->data;

   int left = findMin(root->left, curMin);
   int right = findMin(root->right, curMin);

   if (left < right)
      return left;

   return right;
}
int maxDiffBruteForce(Node* root)
{
   // for each node, find min child, subtract from self, and compare against current maxDiff
   if (!root)
      return INT_MIN;

   int minLeft = findMin(root->left);
   int minRight = findMin(root->right);

   int myMaxDiff = root->data;
   if (minLeft < minRight)
      myMaxDiff = myMaxDiff - minLeft;
   else
      myMaxDiff = myMaxDiff - minRight;

   int maxDiffLeft = maxDiffBruteForce(root->left);
   int maxDiffRight = maxDiffBruteForce(root->right);

   if (maxDiffLeft > myMaxDiff)
      myMaxDiff = maxDiffLeft;
   if (maxDiffRight > myMaxDiff)
      myMaxDiff = maxDiffRight;

   return myMaxDiff;
}


int getMin(Node *node, int *maxDiff) {
   if (node == NULL) return INT_MAX;
   int min_left = getMin(node->left, maxDiff);
   int min_right = getMin(node->right, maxDiff);

   int diff = max(node->data - min_left, node->data - min_right);
   if (diff > *maxDiff) {
      *maxDiff = diff;
   }
   return min(node->data, min(min_left, min_right));
}


int maxDiffOther(Node* root)
{
   // Your code here 
   int maxDiff = INT_MIN;
   getMin(root, &maxDiff);
   return maxDiff;
}