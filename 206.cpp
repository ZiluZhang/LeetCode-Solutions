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
    ListNode* reverseList(ListNode* head) {
        stack<int> nums;
        ListNode* tmp = head;
        while(tmp != NULL)
        {
            nums.push(tmp->val);
            tmp = tmp->next;
        }
        tmp = head;
        while(tmp != NULL)
        {
            tmp->val = nums.top();
            nums.pop();
            tmp = tmp->next;
        }
        return head;
    }
};