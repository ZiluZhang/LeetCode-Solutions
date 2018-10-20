// Swap Nodes in Pairs
// 左右指针都非空，再swap
// 给右指针赋值的时候，要判断左指针非空
// 指针非空永远要记住！！！！！

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return head;
        ListNode* left = head;
        ListNode* right = left->next;
        while(left != NULL && right != NULL) {
            int tmp = left->val;
            left->val = right->val;
            right->val = tmp;
            left = right->next;
            if(left == NULL) break;
            right = left->next;
        }
        return head;
    }
};