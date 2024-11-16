// 543 diameter

// class Solution {
// public:
//     int height(TreeNode* root){
//         if(!root)return 0;
//         return 1+max(height(root->left),height(root->right));
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         if(!root)return 0;
//         int lheight = diameterOfBinaryTree(root->left);
//         int rheight = diameterOfBinaryTree(root->right);
//         int mix = height(root->right)+height(root->left);
//         return max(lheight,max(mix,rheight));
//     }
// };

//optimized diameter

// class Solution {
// public:
//      int D =0 ;
//     int height(TreeNode* root){
//         if(!root)return 0;
//         int lh = height(root->left),rh=height(root->right);
//         D=max(D,lh+rh);
//         return 1+max(lh,rh);
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         if(!root)return 0;
//         // int lheight = diameterOfBinaryTree(root->left);
//         // int rheight = diameterOfBinaryTree(root->right);
//         // int mix = height(root->right)+height(root->left);
//         height(root);
//         return D;
//     }
// };

//leetcode 110 - optimized 
// class Solution {
// public:
//     bool ans = true;
//     int height(TreeNode* root){
//         if(!root) return 0;
//         int l = height(root->right);
//         int r = height(root->left);
//         ans &= (abs(l-r)<=1);
//         return 1+max(l,r);
//     }
//     bool isBalanced(TreeNode* root) {
//         height(root);
//         return ans ;
//     }
// };

//leetcode 100 
// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if(!p && !q) return true ;
//         if(p&&q){
//             return (p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
//         }
//         return false;
//     }
// };

// 101 - symmetric tree ...... 
// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if(!p && !q) return true ;
//         if(p&&q){
//             return (p->val==q->val) && isSameTree(p->left,q->right) && isSameTree(p->right,q->left);
//         }
//         return false;
//     }
//     bool isSymmetric(TreeNode* root) {
//        return isSameTree(root->left,root->right); 
//     }
// };

//gfg diagonal traversal method 1 
// void gettraversal(Node* root,int d,map<int,vector<int>>&mp){
//     if(!root) return ;
//     mp[d].push_back(root->data);
//     gettraversal(root->left,d+1,mp);
//     gettraversal(root->right,d,mp);
// }
// vector<int> diagonal(Node *root)
// {
   
//    map<int ,vector<int>> mp ;
//    int d= 0;
//    vector<int>ans;
//    gettraversal(root,d,mp);
//    for(auto it:mp){
//        vector<int> temp = it.second;
//        for(auto it1:temp){
//            ans.push_back(it1);
//        }
//    }
//    return ans ;
// }

//gfg diagonal traversal optimized 
// vector<int> diagonal(Node *root)
// {
//    // your code here
//    vector<int>ans ;
//    if(!root) return  ans ;
//    queue<Node*>q;
//    q.push(root);
//    while(!q.empty()){
//        Node* front = q.front();
//        q.pop();
//        while(front){
//            ans.push_back(front->data);
//            if(front->left) q.push(front->left);
//            front=front->right;
//        }
//    }
//    return ans;
// }

//vertical order traversal 
// class Solution {
// public:
//     void getTraversal(TreeNode* root, map<int, map<int, multiset<int>>>& mp, int row, int col) {
//         if (!root) return;
//         mp[col][row].insert(root->val);
//         getTraversal(root->left, mp, row + 1, col - 1);
//         getTraversal(root->right, mp, row + 1, col + 1);
//     }

//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         map<int, map<int, multiset<int>>> mp;
//         vector<vector<int>> ans;
//         getTraversal(root, mp, 0, 0);

//         for (auto& col : mp) {
//             vector<int> columnValues;
//             for (auto& row : col.second) {
//                 columnValues.insert(columnValues.end(), row.second.begin(), row.second.end());
//             }
//             ans.push_back(columnValues);
//         }
//         return ans;
//     }
// };
//


//103 zig zag traversal

// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         vector<vector<int>> ans ;
//         if(!root) return ans ;
//         bool toggle = true ;
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()){
//             int levelsize = q.size();
//             vector<int> level(levelsize);
//             for(int i=0;i<levelsize;i++){
//                 TreeNode* front = q.front();
//                 q.pop();
//                 int idx = toggle?i:levelsize-i-1;
//                 level[idx]=front->val;
//                 if(front->left) q.push(front->left);
//                 if(front->right)q.push(front->right);
//             }
//             toggle=!toggle;
//             ans.push_back(level);
//         }
//         return ans ;
//     }
// };

// gfg transform to sum tree 
// class Solution {
//   public:
//     int createSumTree(Node* root){
//         if(!root) return 0;
//         int leftans = createSumTree(root->left);
//         int rightans = createSumTree(root->right);
//         int toreturn = root->data + leftans+rightans;
//         root->data = leftans+rightans;
//         return toreturn;
//     }
//     // Convert a given tree to a tree where every node contains sum of values of
//     // nodes in left and right subtrees in the original tree
//     void toSumTree(Node *node)
//     {
//        createSumTree(node);
//     }
// };

// 437 ksum path or path sum iii
// class Solution {

// public:
//     int ans =0 ;
//     void getNoOfPath(TreeNode* root,long long  targetSum){
//         if(!root) return ;
//         if(targetSum==root->val) ans++;
//         getNoOfPath(root->left,targetSum-root->val);
//         getNoOfPath(root->right,targetSum-root->val);
//     }
//     int pathSum(TreeNode* root, long long targetSum) {
//         if(root){
//             getNoOfPath(root,targetSum);
//             pathSum(root->right,targetSum);
//             pathSum(root->left,targetSum);
//         }
        
//         return ans ;
//     }
// };

//ksumpath gfg 
// class Solution {
//   public:
//   int ans =0 ;
//     void getNoOfPath(Node* root,long long  targetSum){
//         if(!root) return ;
//         if(targetSum==root->data) ans++;
//         getNoOfPath(root->left,targetSum-root->data);
//         getNoOfPath(root->right,targetSum-root->data);
//     }
//     int sumK(Node *root, int targetSum) {
//        if(root){
//             getNoOfPath(root,targetSum);
//             sumK(root->right,targetSum);
//             sumK(root->left,targetSum);
//         }
        
//         return ans ;
//     }
// };

// //morris traverlsal inorder leetcode 94
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> ans ;
//         TreeNode* curr =root ;
//         if(!root) return ans ;
//         while(curr){
//             if(curr->left==NULL){
//                 ans.push_back(curr->val);
//                 curr=curr->right;
//             }
//             else{
//                 TreeNode* pred = curr->left;
//                 while(pred->right && pred->right!=curr){
//                     pred=pred->right;
//                 }
//                 if(pred->right==NULL){
//                     pred->right=curr;
//                     curr=curr->left;
//                 }
//                 else{
//                     pred->right=NULL;
//                     ans.push_back(curr->val);
//                     curr=curr->right;
//                 }
//             }
//         }
//         return ans;
//     }
// }; 

// //gfg sum of longest blood line 
// class Solution
// {
// public:
//     pair<int,int> height (Node* root){
//         if(!root) return {0,0};
//         auto leftheightData = height(root->left);
//         auto rightheightData= height(root->right);
//         int sum = root->data;
//         if(leftheightData.first==rightheightData.first) {
//             return {rightheightData.first+1,sum+max(rightheightData.second,leftheightData.second)};
//         }
//         if(leftheightData.first>rightheightData.first){
//             return {leftheightData.first+1,sum+leftheightData.second};
//         }
//         else if(leftheightData.first<rightheightData.first){
//             return {rightheightData.first+1,sum+rightheightData.second};
//         }
        
//     }
//     int sumOfLongRootToLeafPath(Node *root)
//     {
//         auto h = height(root);
//         return h.second;
//     }
// };

// maximum sum of non adjacent nodes
// class Solution{
//   public:
//     //Function to return the maximum sum of non-adjacent nodes.
//     pair <int , int> getmaxsum (Node * root){
//         if(!root) return {0,0};
//         auto left= (getmaxsum(root->left));
//         auto right= (getmaxsum(root->right));
//         int a  = root->data + left.second+right.second;
//         int b  = max(left.first,left.second)+max(right.first,right.second);
//         return {a,b};
        
//     } 
//     int getMaxSum(Node *root) 
//     {
//     auto k =    getmaxsum(root);
        
//     return max(k.first,k.second );
//         // Add your code here
//     }
// };

// gfg burning tree 

// class Solution {
//   public:
//     Node* parentToChildAndFindTarget(Node* root,int target ,unordered_map<Node*,Node*>& parentToChild){
//         queue<Node*>q;
//         q.push(root);
//         Node* targetFound=NULL;
//         parentToChild[root]=NULL;
//         while(!q.empty()){
//             Node* front = q.front();
//             q.pop();
//             if(front->data == target) targetFound = front ;
//             if(front->left){
//                 q.push(front->left);
//                 parentToChild[front->left] = front;
//             }
//             if(front->right){
//                 q.push(front->right);
//                 parentToChild[front->right]= front;
//             }
//         }
//         return targetFound;
//     }
//     int findthetime(Node* targetNode,unordered_map<Node*,Node*>&parentToChild){
//         unordered_map<Node*,bool>isBurnt;
//         queue<Node*>q;
//         q.push(targetNode);
//         isBurnt[targetNode] =true;
//         int T =0 ;
//         while(!q.empty()){
//             int size = q.size();
//             bool firespread = false;
//             for(int i=0;i<size;i++){
//                 Node* front  = q.front();
//                 q.pop();
//                 if(front->left && !isBurnt[front->left]){
//                     q.push(front->left);
//                     isBurnt[front->left] =true;
//                     firespread=true;
//                 }
//                 if(front->right && !isBurnt[front->right]){
//                     q.push(front->right);
//                     isBurnt[front->right] =true;
//                     firespread=true;
//                 }
//                 if(parentToChild[front] && !isBurnt[parentToChild[front]]){
//                     q.push(parentToChild[front]);
//                     isBurnt[parentToChild[front]]=true;
//                     firespread =true;
//                 }
//             }
//             if(firespread) T++;
//         }
//         return T;
//     }
//     int minTime(Node* root, int target) 
//     {
//         // Your code goes here
//         unordered_map<Node*,Node*> parentToChild;
//         Node* targetNode =parentToChildAndFindTarget(root,target,parentToChild);
//         return findthetime(targetNode,parentToChild);
//     }
// };

// //652 find duplicate subtrees in a binary tree
// class Solution {
// public:
//     unordered_map<string,int> mp ;
//     vector<TreeNode*> ans ;
//     string encode(TreeNode* root){
//         if(!root) return "$";
//         string left = encode(root->left);
//         string right  = encode(root->right);
//         string encodedString =to_string(root->val) +","+left+","+right;
//         if(mp[encodedString]==1) ans.push_back(root);
//         mp[encodedString] ++;
//         return encodedString;
//     }
//     vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
//         if(!root)return ans ;
//         encode(root);
//         return ans ;
//     }
// };