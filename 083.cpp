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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* tmp = new ListNode(0);
        ListNode* cur = tmp;
        while(head != NULL)
        {
            int num = head->val;
            cur->next = new ListNode(num);
            while(head != NULL && head->val == num)
                head = head->next;
            cur = cur->next;
        }
        return tmp->next;
    }
};