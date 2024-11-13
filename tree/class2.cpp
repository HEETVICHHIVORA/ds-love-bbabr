#include<iostream>
#include<queue>
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
  // n l r
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}
void inorder(Node *root)
{
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
int searchinorder(int in[],int size,int element){
  // use map to find position in o1 
    for(int i=0;i<size;i++){
        if(in[i]==element){
            return i ;
        }
    }
}

Node * createtree(int pre[],int in[],int &preindex,int inorderstart ,int inorderend,int size){
if(preindex>=size||inorderstart>inorderend){
    return NULL;
}
int element = pre[preindex];
preindex++;
Node* root = new Node(element);
int position  = searchinorder(in,size,element);
root->left = createtree( pre, in, preindex, inorderstart , position-1, size);
root->right= createtree( pre, in, preindex, position+1,inorderend, size);
return root ;
}

Node * createtree2(int post[],int in[],int &postindex,int inorderstart ,int inorderend,int size){
if(postindex<0||inorderstart>inorderend){
    return NULL;
}
int element = post[postindex];
postindex--;
Node* root = new Node(element);
int position  = searchinorder(in,size,element);
root->right= createtree2( post, in, postindex, position+1,inorderend, size);
root->left = createtree2( post, in, postindex,inorderstart,position-1, size);

return root ;
}




int main (){

    int post[]={8,6,14,4,10,2};
    int in []={8,14,6,2,10,4};
    int size=6;
    int preindex=0;
    int postindex=size-1;
    int inoderindex=0;
    int inorderstart=0;
    int indorderend=5;
    

Node* root = createtree2(post, in, postindex, inorderstart , indorderend, size);
leveltrav(root);
    return 0 ;
} 


//--->leetcode 110 balanced b-tree.
 
// class Solution {
// public:
//     int height(TreeNode* root){
//         if(!root) return 0;
//         return 1+max(height(root->right),height(root->left));
//     }
//     bool isBalanced(TreeNode* root) {
//         if(!root) return true;
//         int lh = height(root->left);
//         int rh = height(root->right);
//         bool currans = abs(lh-rh)<=1;
//         bool lans = isBalanced(root->left);
//         bool rans = isBalanced(root->right);
//         return currans&&lans&&rans ? true :false;
//     }
// };

  //--> leetcode 236 
//   class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(!root) return NULL;
//         if(root== p) return p;
//         if(root== q) return q;
//         TreeNode* left = lowestCommonAncestor(root->left,p,q);
//         TreeNode* right= lowestCommonAncestor(root->right,p,q);
//         if(left ==NULL && right==NULL) return NULL ;
//         else if(left ==NULL && right!=NULL) return right;
//         else if(left !=NULL && right==NULL) return left;
//         return root ;
//     }
// };

//leetcode -> 112 
//pathsum 
// class Solution {
// public:
//     bool hasPathSum(TreeNode* root, int targetSum) {
//         if (!root) return false;
//         if (!root->left && !root->right && targetSum == root->val) {
//             return true;
//         }
//         return hasPathSum(root->left, targetSum - root->val) || 
//                hasPathSum(root->right, targetSum - root->val);
//     }
// };

//leetcode 113 

//pathsumii

// class Solution {
// public:
//     void hasPathSum(TreeNode* root, int targetSum,vector<int>&temp,vector<vector<int>> &ans) {
//         if (!root) return;
//         temp.push_back(root->val);
//         if (!root->left && !root->right && targetSum == root->val){
//             ans.push_back(temp);
//         } 
//         else{
//             hasPathSum(root->left, targetSum - root->val,temp,ans);
//             hasPathSum(root->right, targetSum - root->val,temp,ans);
//         }
//         temp.pop_back();
//     }
//     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//         vector<vector<int>>ans ;
//         vector<int> temp ;
//         if (!root) return ans;
//         hasPathSum(root,targetSum,temp,ans);
//         return ans ;
//     }
// };

// gfg kth ancestor 

// Node* solve(Node* root, int& k, int node, int& ans) {
//     if (!root) return NULL;

   
//     if (root->data == node) return root;

  
//     Node* leftans = solve(root->left, k, node, ans);
//     Node* rightans = solve(root->right, k, node, ans);

    
//     if (leftans || rightans) {
//         k--;
//         if (k == 0) {
//             ans = root->data;  
//             return NULL;      
//         }
//         return leftans ? leftans : rightans;
//     }

//     return NULL;
// }

// int kthAncestor(Node* root, int k, int node) {
//     int ans = -1;
//     solve(root, k, node, ans);
//     return ans;
// }

