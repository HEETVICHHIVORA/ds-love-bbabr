#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
  int data;
  Node *left;
  Node *right;
  Node(int val)
  {
    this->data = val;
    this->left = NULL;
    this->right = NULL;
  }
};
Node *create()
{
  int data;
  cin >> data;
  if (data == -1)
  {
    return NULL;
  }
  Node *newNode = new Node(data);
  newNode->left = create();
  newNode->right = create();
  return newNode;
}
void preorder(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  //nlr
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}
void inorder(Node *root)
{
  //lnr
  if (root == NULL)
  {
    return;
  }
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}
void post(Node *root)
{
  //lrn
  if (root == NULL)
  {
    return;
  }
  post(root->left);
  post(root->right);
  cout << root->data << " ";
}
void leveltrav(Node *root)
{
  queue<Node *> q;
  q.push(root);
  q.push(NULL);
  while (q.size() > 1)
  {
    Node *front = q.front();
    q.pop();
    if (front == NULL)
    {
      cout << endl;
      q.push(NULL);
    }
    else
    {
      cout << front->data << " ";
      if (front->left != NULL)
      {
        q.push(front->left);
      }
      if (front->right)
      {
        q.push(front->right);
      }
    }
  }
}
// leetcode 104 (12/11/2024)

// int maxDepth(TreeNode* root) {
//         if(root==NULL) return 0 ;
//         return 1+ max(maxDepth(root->left),maxDepth(root->right));
// }

// leetcode 543 (12/11/2024)

// class Solution {
// public:
// int maxDepth(TreeNode* root) {
//         if(root==NULL){
//             return 0;
//         }
    
//         int lheight = maxDepth(root->left);
//         int rheight = maxDepth(root->right);
//         int ans  = max(lheight,rheight);
//         ans ++ ;
//         return ans ;
// }
//     int diameterOfBinaryTree(TreeNode* root) {
//         if(root==NULL){
//             return 0;
//         }
//       int  ans = 0;
//         int lheight = diameterOfBinaryTree(root->left);
//         int rheight = diameterOfBinaryTree(root->right);
//         int mix =maxDepth(root->left)+maxDepth(root->right);
//         ans = max(lheight,max(mix,rheight));
//         return ans ;
//     }
// };


int main()
{
  Node *root = create();
  cout << "inoder: ";
  inorder(root);
  cout << endl;
  cout << "preoder: ";
  preorder(root);
  cout << endl;
  cout << "postoder: ";
  post(root);
  cout << endl;
  leveltrav(root);
  cout << endl;
  return 0;
}