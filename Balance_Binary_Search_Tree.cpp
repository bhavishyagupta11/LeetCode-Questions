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
    TreeNode* construct(int l, int r, vector<int>& sortedArray) {
        if(l>r) return NULL;

        int mid = l + (r-l)/2;

        TreeNode* root = new TreeNode(sortedArray[mid]);

        root->left = construct(l, mid-1, sortedArray);
        root->right = construct(mid+1, r, sortedArray);

        return root;
    }
    void inOrder(TreeNode* root, vector<int>& sortedArray) {
        if(!root) return;
        inOrder(root->left, sortedArray);
        sortedArray.push_back(root->val);
        inOrder(root->right, sortedArray);
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(root==NULL) return NULL;

        vector<int>sortedArray;
        inOrder(root, sortedArray);

        int l = 0;
        int r = sortedArray.size()-1;
        return construct(l, r, sortedArray);    
    }
};