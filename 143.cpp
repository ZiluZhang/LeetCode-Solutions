// Reorder List
// 先用快慢指针找到中点，把两段分开
// 后半段reverse
// 两段插起来


class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        ListNode* lasthalf = mid;
        ListNode* pre = NULL;
        // reverse last half list
        while(lasthalf) {
            ListNode* nxt = lasthalf->next;
            lasthalf->next = pre;
            pre = lasthalf;
            lasthalf = nxt;
        }
        // insert
        while(head && pre) {
            ListNode* nxt = head->next;
            head->next = pre;
            pre = pre->next;
            head->next->next = nxt;
            head = nxt;
        }
    }
};