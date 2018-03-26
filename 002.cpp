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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* tmp = res;
        int s = 0;
        while(l1 != NULL && l2 != NULL)
        {
            int num1 = l1->val;
            int num2 = l2->val;
            tmp->next = new ListNode((num1 + num2 + s) % 10);
            s = (num1 + num2 + s) / 10;
            tmp = tmp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL)
        {
            int num1 = l1->val;
            tmp->next = new ListNode((num1 + s) % 10);
            s = (num1 + s) / 10;
            tmp = tmp->next;
            l1 = l1->next;
        }
        while(l2 != NULL)
        {
            int num2 = l2->val;
            tmp->next = new ListNode((num2 + s) % 10);
            s = (num2 + s) / 10;
            tmp = tmp->next;
            l2 = l2->next;
        }
        if(s > 0)
            tmp->next = new ListNode(s);
        return res->next;
    }
};