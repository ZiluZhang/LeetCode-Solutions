/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        queue<TreeNode*> tmp;
        TreeNode* cur;
        q.push(root);
        int leftmost = root->val;
        while(!q.empty())
        {
            cur = q.front();
            leftmost = cur->val;
            while(!q.empty())
            {
                cur = q.front();
                if(cur->left != NULL)
                    tmp.push(cur->left);
                if(cur->right != NULL)
                    tmp.push(cur->right);
                q.pop();
            }
            while(!tmp.empty())
            {
                q.push(tmp.front());
                tmp.pop();
            }
        }
        return leftmost;
    }
};