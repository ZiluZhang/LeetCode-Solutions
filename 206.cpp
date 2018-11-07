// Reverse Linked List
// 递归和迭代，见代码


class Solution {
public:
    // 递归
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* tmp = head->next;
        head->next = NULL;
        // 拿到后面reverse之后的结果
        ListNode* newtmp = reverseList(tmp);
        // tmp地址不变，指向元素不变，只是元素在list中位置变了
        tmp->next = head;
        return newtmp;
    }
    // 迭代
    // 三个指针
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* tmp1 = head;
        ListNode* tmp2 = head->next;
        ListNode* tail = NULL;
        while(tmp2 != NULL) {
            tmp1->next = tail;
            ListNode* fwd = tmp2->next;
            tmp2->next = tmp1;
            tail = tmp1;
            tmp1 = tmp2;
            tmp2 = fwd;
        }
        return tmp1;
    }
};