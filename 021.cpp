// Merge Two Sorted Lists
// 判断指针非空再取东西
// 
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
        ListNode* res = new ListNode(0);
        ListNode* tmp = res;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        while(l1 != NULL && l2 != NULL) {
            if(l1->val < l2->val) {
                tmp->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else {
                tmp->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            tmp = tmp->next;
        }
        while(l1 != NULL) {
            tmp->next = new ListNode(l1->val);
            tmp = tmp->next;
            l1 = l1->next;
        }
        while(l2 != NULL) {
            tmp->next = new ListNode(l2->val);
            tmp = tmp->next;
            l2 = l2->next;
        }
        return res->next;
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
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         if(l1 == NULL && l2 == NULL)
//             return NULL;
//         ListNode* res = new ListNode(-1);
//         ListNode* m = res;
//         while(l1 != NULL && l2 != NULL)
//         {
//             if(l1->val < l2->val)
//             {
//                 m->val = l1->val;
//                 l1 = l1->next;
//             }
//             else
//             {
//                 m->val = l2->val;
//                 l2 = l2->next;
//             }
//             m->next = new ListNode(-1);
//             m = m->next;
//         }
//         if(l1 != NULL)
//         {
//             m->val = l1->val;
//             m->next = l1->next;
//         }
//         else if(l2 != NULL)
//         {
//             m->val = l2->val;
//             m->next = l2->next;
//         }
//         else
//             delete m;
//         return res;
//     }
// };