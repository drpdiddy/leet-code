/*
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such
 that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

Example 1:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: false
Example 3:

Input: root = [1,2], targetSum = 0
Output: false


Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
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
   int targetSum;
public:
   bool isPathSumCorrect(TreeNode* root, int currentSum) {

       if (root==NULL)
           return false;

       bool answer = false;
       currentSum += root->val;

       if (root->left==NULL && root->right==NULL)
          answer = answer || currentSum==this->targetSum;

       if (!answer && root->left != NULL)
         answer = answer || isPathSumCorrect(root->left, currentSum);

       if (!answer && root->right != NULL)
         answer = answer || isPathSumCorrect(root->right, currentSum);

       return answer;

   }

   bool hasPathSum(TreeNode* root, int targetSum) {
        this->targetSum = targetSum;
        int currentSum = 0;
        return isPathSumCorrect(root, currentSum);
   }
};