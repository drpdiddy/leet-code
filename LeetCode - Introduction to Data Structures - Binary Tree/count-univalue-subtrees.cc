
/*Given the root of a binary tree, return the number of uni-value subtrees.

A uni-value subtree means all nodes of the subtree have the same value.

Example 1:

Input: root = [5,1,5,5,5,null,5]
Output: 4
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [5,5,5,5,5,null,5]
Output: 6


Constraints:

The numbrt of the node in the tree will be in the range [0, 1000].
-1000 <= Node.val <= 1000
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
    int uniValueCount;
public:
    int findTheValue(TreeNode *root) {

       if (root==NULL)
          return std::numeric_limits<int>::min();

       auto value = root->val;

       if (root->left==NULL && root->right==NULL){
          this->uniValueCount++;
          return value;
       }

       int leftValue = findTheValue(root->left);
       int rightValue = findTheValue(root->right);

       if ((leftValue == std::numeric_limits<int>::min() || leftValue == value)
       && (rightValue == std::numeric_limits<int>::min() || rightValue == value)) {
           this->uniValueCount++;
       } else {
         value = std::numeric_limits<int>::max();
       }

       return value;
    }

    int countUnivalSubtrees(TreeNode* root) {
        this->uniValueCount = 0;
        findTheValue(root);
        return this->uniValueCount;
    }
};