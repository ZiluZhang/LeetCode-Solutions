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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL)
            return NULL;
        ListNode* res = new ListNode(-1);
        ListNode* m = res;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2->val)
            {
                m->val = l1->val;
                l1 = l1->next;
            }
            else
            {
                m->val = l2->val;
                l2 = l2->next;
            }
            m->next = new ListNode(-1);
            m = m->next;
        }
        if(l1 != NULL)
        {
            m->val = l1->val;
            m->next = l1->next;
        }
        else if(l2 != NULL)
        {
            m->val = l2->val;
            m->next = l2->next;
        }
        else
            delete m;
        return res;
    }
};