// Recover Binary Search Tree
// BST中交换了两个点，找到并且换回来
// 中序遍历，找错点
// 如果错点相邻，那么只能发现一处pre->val < root->val
// 如果错点不相邻，能发现两处，交换第一处的pre和第二处的root就行了

// 1，2，4，3，5，6，7 错点只有4-3处
// 1，5，3，4，2，6，7 错点为5-3处和4-2处
class Solution {
public:
    TreeNode* pre;
    TreeNode* tmp1;
    TreeNode* tmp2;
    void recoverTree(TreeNode* root) {
        pre = NULL;
        tmp1 = NULL;
        tmp2 = NULL;
        if(!root) return;
        inorder(root);
        if(tmp1 && tmp2) swap(tmp1->val, tmp2->val);
        return;
    }
    
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        if(!pre) {
            pre = root;
        }
        else {
            if(pre->val > root->val) {
                if(!tmp1) {
                    tmp1 = pre;
                }
                tmp2 = root;
            }
            pre = root;
        }
        inorder(root->right);
        return;
    }
};