// Path Sum II
// 如何维护当前list！记得return前要去掉加入的
// myvector.pop_back()
// 

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return {};
        vector<vector<int>> res;
        vector<int> cur;
        findPath(root, sum, cur, res);
        return res;
    }
    
    void findPath(TreeNode* root, int sum, vector<int>& cur, vector<vector<int>>& res) {
        if(!root) return;
        cur.push_back(root->val);
        if(!root->left && !root->right && root->val == sum) {
            res.push_back(cur);
        }
        if(root->left) findPath(root->left, sum-root->val, cur, res);
        if(root->right) findPath(root->right, sum-root->val, cur, res);
        cur.pop_back();
        return;
    }
};


// class Solution {
// public:
//     vector<vector<int>> pathSum(TreeNode* root, int sum) {
//         vector<vector<int>> res;
//         if(root == NULL)
//             return res;
//         vector<int> tmp;
//         getpath(root, tmp, sum, res);
//         return res;
//     }
    
//     void getpath(TreeNode* cur, vector<int> prev, int remain, vector<vector<int>>& res)
//     {
//         if(cur == NULL)
//             return;
//         remain -= cur->val;
//         prev.push_back(cur->val);
//         if(remain == 0 && cur->left == NULL && cur->right == NULL)
//         {
//             res.push_back(prev);
//             return;
//         }
//         else if(cur->left != NULL || cur->right != NULL)
//         {
//             getpath(cur->left, prev, remain, res);
//             getpath(cur->right, prev, remain, res);
//         }
//         return;
//     }
// };