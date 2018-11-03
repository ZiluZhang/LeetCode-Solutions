// Populating Next Right Pointers in Each Node
// tmp是用来找每一层最开始的节点！tmp->next就是
// 


class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        TreeLinkNode* tmp = new TreeLinkNode(-1);
        TreeLinkNode* prev = tmp;
        while(root) {
            if(root->left) {
                prev->next = root->left;
                prev = prev->next;
            }
            if(root->right) {
                prev->next = root->right;
                prev = prev->next;
            }
            root = root->next;
            if(!root) {
                prev = tmp;
                root = tmp->next;
                tmp->next = NULL; // 记得赋空，这样while(root)到最后一层才能停止
            }
        }
        return;
    }
};