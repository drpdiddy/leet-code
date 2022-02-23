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
    void visitNode(TreeNode* node) {

        if (node->left != NULL)
           visitNode(node->left);

        nodes.push_back(node->val);

        if (node->right != NULL)
           visitNode(node->right);

    }

    vector<int> inorderTraversal(TreeNode* root) {
       this->nodes.clear();

       if (root != NULL)
          visitNode(root);

       return this->nodes;
    }
};