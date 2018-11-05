// Sort List
// 要求nlogn所以用归并！喜欢！
// 用快慢指针找中点，然后前半段排序，后半段排序，写个merge

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = head;
        while(fast && fast->next) {
            pre = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        pre->next = NULL;
        return merge(sortList(head), sortList(slow));
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* tmp = new ListNode(-1);
        ListNode* res = tmp;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                res->next = l1;
                l1 = l1->next;
            }
            else {
                res->next = l2;
                l2 = l2->next;
            }
            res = res->next;
        }
        if(l1) res->next = l1;
        if(l2) res->next = l2;
        return tmp->next;
    }
};