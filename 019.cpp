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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* h1 = new ListNode(0);
        h1->next = head;
        ListNode* h2 = h1;
        ListNode* res = h1;
        for(int i = 0; i <= n; i++)
            h1 = h1->next;
        while(h1 != NULL)
        {
            h1 = h1->next;
            h2 = h2->next;
        }
        // h1 = h2->next;
        h2->next = h2->next->next;
        // delete h1;
        return res->next;
    }
};