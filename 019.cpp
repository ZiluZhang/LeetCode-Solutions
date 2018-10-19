// Remove Nth Node From End of List
// 先看list有多长，然后就知道了要删除正数第几个
// 注意边界：如果list为空，如果要删除的是第一个
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
        if(head == NULL) return head;
        ListNode* tmp = head;
        int len = 0;
        while(tmp != NULL) {
            tmp = tmp->next;
            len++;
        }
        if(n == len) return head->next;
        ListNode* prev = head;
        tmp = head;
        int idx = len - n + 1;
        for(int i = 0; i < len-n; i++) {
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = tmp->next;
        return head;
    }
};

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* h1 = new ListNode(0);
//         h1->next = head;
//         ListNode* h2 = h1;
//         ListNode* res = h1;
//         for(int i = 0; i <= n; i++)
//             h1 = h1->next;
//         while(h1 != NULL)
//         {
//             h1 = h1->next;
//             h2 = h2->next;
//         }
//         // h1 = h2->next;
//         h2->next = h2->next->next;
//         // delete h1;
//         return res->next;
//     }
// };