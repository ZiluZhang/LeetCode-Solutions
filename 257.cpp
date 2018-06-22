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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL)
            return res;
        string tmp;
        getpath(root, tmp, res);
        return res;
    }
    
    void getpath(TreeNode* cur, string prev, vector<string>& res)
    {
        if(cur == NULL)
            return;
        if(prev.length() != 0)
            prev += "->";
        prev += to_string(cur->val);
        if(cur->left == NULL && cur->right == NULL)
        {
            // if(prev.length() != 0)
            //     prev += "->";
            // prev += to_string(cur->val);
            res.push_back(prev);
            return;
        }
        else
        {
            getpath(cur->left, prev, res);
            getpath(cur->right, prev, res);
        }
        return;
    }
};