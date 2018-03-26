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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return head;
        ListNode* tmp = head;
        while(tmp != NULL && tmp->val == val)
            tmp = tmp->next;
        ListNode* res = tmp;
        while(tmp != NULL)
        {
            while(tmp->next != NULL && tmp->next->val == val)
                tmp->next = tmp->next->next;
            tmp = tmp->next;
        }
        return res;
    }
};