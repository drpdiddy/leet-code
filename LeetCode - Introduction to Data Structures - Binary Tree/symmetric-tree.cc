/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).



Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false


Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100


Follow up: Could you solve it both recursively and iteratively?
*/

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

    bool isMirror(TreeNode *left_node, TreeNode *right_node) {
       if (left_node==NULL && right_node==NULL)
          return true;
       else if (left_node==NULL || right_node==NULL)
          return false;
       else
          return (left_node->val==right_node->val)
               && isMirror(left_node->left, right_node->right)
               && isMirror(left_node->right, right_node->left);
    }

    bool isSymmetric(TreeNode* root) {
       return isMirror(root, root);
    }
};