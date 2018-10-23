// Palindrome Linked List
// 快慢指针，快走两步，慢走一步，找到中间
// fast->next一定要先判断fast非空
// 要是O(1)可以把后半段翻转
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
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;
        ListNode* fast = head;
        ListNode* slow = head;
        stack<int> s;
        while(fast!= NULL && fast->next != NULL) {
            s.push(slow->val);
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast == NULL) // 偶数个，slow在后半段开头
            ;
        else // 奇数个，slow在正中间
            slow = slow->next;
        while(slow != NULL) {
            if(!s.empty() && s.top() != slow->val) return false;
            slow = slow->next;
            s.pop();
        }
        if(!s.empty()) return false;
        return true;
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
//     bool isPalindrome(ListNode* head) {
//         if(head == NULL)
//             return true;
//         ListNode* tmp = head->next;
//         int cnt = 1;
//         while(tmp != NULL)
//         {
//             cnt++;
//             tmp = tmp->next;
//         }
//         cout << cnt << endl;
//         stack<int> num;
//         tmp = head;
//         for(int i = 0; i < cnt/2; i++)
//         {
//             num.push(tmp->val);
//             tmp = tmp->next;
//         }
//         if(cnt%2 == 1)
//             tmp = tmp->next;
//         while(tmp != NULL)
//         {
//             if(tmp->val != num.top())
//                 return false;
//             num.pop();
//             tmp = tmp->next;
//         }
//         if(!num.empty())
//             return false;
//         return true;
//     }
// };