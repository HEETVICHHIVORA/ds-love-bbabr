 #include<iostream>
#include<queue>
#include<climits>

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
class info {
    public :
    int maxval ;
    bool isheap;
    info(int a,bool b){
        this->maxval=a;
        this->isheap=b;
    }
};
info checkifmaxheap(Node* root){
    if(root==NULL){
    info temp(INT_MIN,true) ;
         return temp ;
    }
    if(root->left ==NULL && root->right==NULL){
        info temp(root->data,true) ;
        return temp ;
    }
    info lans = checkifmaxheap(root->left);
    info rans = checkifmaxheap(root->right);
    if(root->data>lans.maxval && root->data>rans.maxval && lans.isheap && rans.isheap){
        info ans(root->data,true);
        return ans ;
    }
    else{
        info ans (max(root->data,max(lans.maxval,rans.maxval)),false);
        return ans ;
    }
};
void preorder(Node* root,int &count){
    if(root==NULL){
        return;
    }
    count++;
    preorder(root->right,count);
    preorder(root->left,count);
}
void storeinorder(Node* root,vector<int>in){
    if(root==NULL){
       return ;
    }
    storeinorder(root->left,in);
    in.push_back(root->data);
    storeinorder(root->right,in);
}
void replace(Node*root,vector<int>in,int index){
    if(root==NULL){
        return;
    }
    replace(root->left,in,index);
    replace(root->right,in,index);
    root->data = in[index];
    index++;
}
void InsertinBst(Node *&root, int data)
{
    // 1st element che !
    if (root == NULL){
        root = new Node(data);
        return;
    }
    else
    {
        if (data > root->data){
            InsertinBst(root->right, data);
        }
        else{
            InsertinBst(root->left, data);
        }
    }
}

void createBst(Node *&root)
{
    cout << "Enter Data : " << endl;
    int x;
    cin >> x;

    while (x != -1){
        InsertinBst(root, x);
        cin >> x;
    }
}
Node* converttobst(Node* root){
    vector<int> inorder;
    storeinorder(root,inorder);
    int index = 0;
    replace(root,inorder,index);
    return root ;
}
void counter(Node*root ,int &count,int count2){
    if(root==NULL && count2>0){
         count++ ;
         return ;
    }
    else if(root==NULL && count2<0){
        return ;
    }
    else{
        count++;
        count2--;
    }
       counter(root->left,count,count2);
       counter(root->right,count,count2);
}
int ksmall(int arr[],int k){
    priority_queue<int>pq;
    for(int i=0;i<k;i++){
      pq.push(arr[i]);
    }
    int n = 7;
    for(int i=k;i<7;i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }

    }
    int ans = pq.top();
    return ans ;
}
int kthbig(int arr[],int k ){
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<k;i++){
      pq.push(arr[i]);
    }
    int n = 7;
    for(int i=k;i<7;i++){
        if(arr[i]>pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }

    }
    int ans = pq.top();
    return ans ;
}
void BFStraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";

            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}
//solve lc 958 -> 
int main (){
    // int arr[]={3,5,4,6,9,8,7};
    // int k = 3;
    // cout<<ksmall(arr,k)<<endl;

    // cout<<kthbig(arr,k)<<endl;
//     Node* root = create();
//     int count = 0;
//     preorder(root,count);
//      int count2=0;
     
//     cout<<count<<endl;
//     counter(root,count2,count);
//    cout<<count2<<endl;
Node* root = NULL;
createBst(root);
BFStraversal(root);
     return 0;
}
//pq.push(k);
//pq.top();
//pq.empty();
//min heap ->  priority_queue<int,vector<int>,greater<int> pq ;


// gfg -> is a binary tree heap ??
// class info {
//     public :
//     int maxval ;
//     bool isheap;
//     info(int a,bool b){
//         this->maxval=a;
//         this->isheap=b;
//     }
// };
// info checkifmaxheap(Node* root){
//     if(root==NULL){
//     info temp(INT_MIN,true) ;
//          return temp ;
//     }
//     if(root->left ==NULL && root->right==NULL){
//         info temp(root->data,true) ;
//         return temp ;
//     }
//     info lans = checkifmaxheap(root->left);
//     info rans = checkifmaxheap(root->right);
//     if(root->data>=lans.maxval && root->data>=rans.maxval && lans.isheap && rans.isheap){
//         info ans(root->data,true);
//         return ans ;
//     }
//     else{
//         info ans (max(root->data,max(lans.maxval,rans.maxval)),false);
//         return ans ;
//     }
// };
// class Solution {
//   public:
//     bool checkifcbt(Node* root) {
//         if (!root)  return true;
//         queue<Node*> q;
//         q.push(root);
//         bool iscbt=false;
//         while(!q.empty()){
//             Node* front  = q.front();
//             q.pop();
//             if(front==NULL) iscbt=true;
//             else{
//                 if(iscbt) return false;
//                 q.push(front->left);
//                 q.push(front->right);
//             }
//         }
//         return true ;
//     }

//     bool isHeap(struct Node* tree) {
//         if (!tree) return true; 
//         bool ans1 = checkifcbt(tree);
//         if (!ans1) return false;
//         auto ans2 = checkifmaxheap(tree);
//         return ans2.isheap;
//     }
// };

 