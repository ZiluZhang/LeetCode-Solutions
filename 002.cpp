// 在while循环的时候，记得update循环变量
// 大整数加法，记得最后加完如果还有进位，要加上
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
        ListNode* tmp1 = l1;
        ListNode* tmp2 = l2;
        int c = 0;
        int addres = 0;
        ListNode* res = new ListNode(0);
        ListNode* restmp = res;
        while(tmp1 != NULL && tmp2 != NULL) {
            addres = tmp1->val + tmp2->val + c;
            c = addres / 10;
            addres %= 10;
            restmp->next = new ListNode(addres);
            restmp = restmp->next;
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        while(tmp1 != NULL) {
            addres = tmp1->val + c;
            c = addres / 10;
            addres %= 10;
            restmp->next = new ListNode(addres);
            restmp = restmp->next;
            tmp1 = tmp1->next;
        }
        while(tmp2 != NULL) {
            addres = tmp2->val + c;
            c = addres / 10;
            addres %= 10;
            restmp->next = new ListNode(addres);
            restmp = restmp->next;
            tmp2 = tmp2->next;
        }
        if(c != 0) {
            restmp->next = new ListNode(c);
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
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* res = new ListNode(0);
//         ListNode* tmp = res;
//         int s = 0;
//         while(l1 != NULL && l2 != NULL)
//         {
//             int num1 = l1->val;
//             int num2 = l2->val;
//             tmp->next = new ListNode((num1 + num2 + s) % 10);
//             s = (num1 + num2 + s) / 10;
//             tmp = tmp->next;
//             l1 = l1->next;
//             l2 = l2->next;
//         }
//         while(l1 != NULL)
//         {
//             int num1 = l1->val;
//             tmp->next = new ListNode((num1 + s) % 10);
//             s = (num1 + s) / 10;
//             tmp = tmp->next;
//             l1 = l1->next;
//         }
//         while(l2 != NULL)
//         {
//             int num2 = l2->val;
//             tmp->next = new ListNode((num2 + s) % 10);
//             s = (num2 + s) / 10;
//             tmp = tmp->next;
//             l2 = l2->next;
//         }
//         if(s > 0)
//             tmp->next = new ListNode(s);
//         return res->next;
//     }
// };