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
    vector<int> nodes;

public:
    void visitNode(TreeNode *root){
        if (root!=NULL) {
            this->nodes.push_back(root->val);
            visitNode(root->left);
            visitNode(root->right);
        }
    }

    vector<int> preorderTraversal(TreeNode *root) {
        nodes.clear();
        visitNode(root);
        return this->nodes;
    }
};