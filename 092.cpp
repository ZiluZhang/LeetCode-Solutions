// Reverse Linked List II
// in one pass
// 链表，头插法

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || head->next == NULL || m == n) return head;
        ListNode* tmp = new ListNode(0);
        tmp->next = head;
        ListNode* prev = tmp;
        for(int i = 0; i < m-1; i++)
            prev = prev->next;
        ListNode* p1 = prev->next;
        ListNode* p2 = p1->next;
        for(int i = m; i < n; i++) {
            p1->next = p2->next;
            p2->next = prev->next;
            prev->next = p2;
            p2 = p1->next;
        }
        return tmp->next;
    }
};