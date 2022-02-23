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
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> values;
       values.clear();
       list<TreeNode> nodes;

       if (root!=NULL)
           nodes.push_back(*root);

       while (nodes.size() > 0){

          TreeNode node = nodes.back();

          if (node.left!=NULL) {
              nodes.push_back(*node.left);
          } else if (node.left==NULL) {
             values.push_back(node.val);
             nodes.pop_back();
             if (nodes.size()>0) {
                TreeNode& parent = nodes.back();
                parent.left = NULL;
             }
             if (node.right!=NULL)
                nodes.push_back(*node.right);
          }

       }
       return values;
    }
};