// Populating Next Right Pointers in Each Node
// 树本身结构有很强限制！非常完美的树！

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

// O(1)空间
// 从每一层最左边开始！用上一层的next来搞
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        TreeLinkNode* cur = root;
        root->next = NULL;
        while(cur->left) {
            TreeLinkNode* tmp = cur;
            while(tmp) {
                tmp->left->next = tmp->right;
                tmp->right->next = tmp->next ? tmp->next->left: NULL;
                tmp = tmp->next;
            }
            cur = cur->left;
        }
        return;
    }
};

// 递归
// cur->left->next=cur->right
// cur->right->next=cur->next->left 或 NULL
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        if(root->left) root->left->next = root->right;
        if(root->right) root->right->next = (root->next) ? root->next->left : NULL;
        connect(root->left);
        connect(root->right);
        return;
    }
};

// 层级遍历，用队列
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while(!q.empty()) {
            for(int i = q.size()-1; i >= 0; i--) {
                TreeLinkNode* cur = q.front();
                q.pop();
                cur->next = i ? q.front(): NULL;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return;
    }
};