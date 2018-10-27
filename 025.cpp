// Reverse Nodes in k-Group
// 头插法，注意边界！
// 三个指针

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k <= 1) return head;
        ListNode* res = new ListNode(0);
        ListNode* tmphead = res;
        res->next = head;
        ListNode* tmp;
        ListNode* prev = res;
        int num = 0; // number of integer in list
        while(head) {
            num++; head = head->next;
        }
        for(int t = 0; t < num/k; t++) {
            tmphead = prev;
            prev = prev->next;
            tmp = prev->next;
            for(int i = 0; i < k-1; i++) {
                prev->next = tmp->next;
                tmp->next = tmphead->next;
                tmphead->next = tmp;
                tmp = prev->next;
            }
        }
        return res->next;
    }
};