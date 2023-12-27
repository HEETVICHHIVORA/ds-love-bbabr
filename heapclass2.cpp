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
info check(Node* root){
    if(root==NULL){
    info temp(INT_MIN,true) ;
         return temp ;
    }
    if(root->left ==NULL && root->right==NULL){
        info temp(root->data,true) ;
        return temp ;
    }
    info lans = check(root->left);
    info rans = check(root->right);
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
// void preorder(Node *root)
// {
//   if (root == NULL)
//   {
//     return;
//   }
//   // n l r
//   cout << root->data << " ";
//   preorder(root->left);
//   preorder(root->right);
// }
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
pair<int,bool> maxi(Node* root){
    pair<int ,bool>a;
    if(root==NULL){
        
    }
}
//solve lc 958 ->
int main (){
    // int arr[]={3,5,4,6,9,8,7};
    // int k = 3;
    // cout<<ksmall(arr,k)<<endl;

    // cout<<kthbig(arr,k)<<endl;
    Node* root = create();
    int count = 0;
    preorder(root,count);
     int count2=0;
     
    cout<<count<<endl;
    counter(root,count2,count);
   cout<<count2<<endl;

    return 0;
}
//pq.push(k);
//pq.top();
//pq.empty();
//min heap -> priority_queue<int,vector<int>,greater<int> pq ;


