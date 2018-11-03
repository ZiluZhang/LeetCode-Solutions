// Convert Sorted List to Binary Search Tree
// 递归
// 用快慢指针找中间点，偶数时偏左偏右都没关系！想想tree节点数！
// 要用prev记录前一个，找到中间之后，把前一个的next赋空，所以就分开了！
// 然后再递归找前半部分，找后半部分
// 

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val);
        // 快慢指针
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = head;
        while(fast->next && fast->next->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        prev->next = NULL;
        TreeNode* parent = new TreeNode(slow->val);
        if(head != slow)
            parent->left = sortedListToBST(head);
        parent->right = sortedListToBST(fast);
        return parent;
    }
};