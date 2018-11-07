// Binary Tree Right Side View
// 输出的是每一层最右侧的节点
// BFS queue
// while内每层循环之前，把queue中最后一个元素加到结果中
// myqueue.back()

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            res.push_back(q.back()->val);
            for(int i = q.size(); i > 0; i--) {
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return res;
    }
};