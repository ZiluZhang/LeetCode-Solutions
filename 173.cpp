// Binary Search Tree Iterator
// 维护一个栈
// 每一次的next smallest number就是栈顶元素
// 栈顶有right，把right的所有left都推栈，这样栈顶依然是next smallest


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode *root) {
        while(root != NULL) {
            s.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* t = s.top();
        s.pop();
        int res = t->val;
        if(t->right != NULL) {
            t = t->right;
            while(t != NULL) {
                s.push(t);
                t = t->left;
            }
        }
        return res;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */