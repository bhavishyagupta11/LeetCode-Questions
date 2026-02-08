/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root) {
        if(!root) return 0;

        int left = height(root->left);
        int right = height(root->right);

        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        if(abs(height(root->right)-height(root->left)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

// class Solution {
// public:
//     int height(TreeNode* root) {
//         if(root==NULL) return 0;
        
//         int left = height(root->left);
//         if(left == -1) return -1;

//         int right = height(root->right);
//         if(right == -1) return -1;

//         if(abs(right-left) > 1) return -1;

//         return 1 + max(right,left);
//     }
//     bool isBalanced(TreeNode* root) {
//     return height(root) != -1;
//     }
// };