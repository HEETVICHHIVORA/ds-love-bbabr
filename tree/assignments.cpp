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


