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
        if(head == NULL)
            return true;
        ListNode* tmp = head->next;
        int cnt = 1;
        while(tmp != NULL)
        {
            cnt++;
            tmp = tmp->next;
        }
        cout << cnt << endl;
        stack<int> num;
        tmp = head;
        for(int i = 0; i < cnt/2; i++)
        {
            num.push(tmp->val);
            tmp = tmp->next;
        }
        if(cnt%2 == 1)
            tmp = tmp->next;
        while(tmp != NULL)
        {
            if(tmp->val != num.top())
                return false;
            num.pop();
            tmp = tmp->next;
        }
        if(!num.empty())
            return false;
        return true;
    }
};