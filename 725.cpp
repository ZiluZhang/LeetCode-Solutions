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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode* tmp = root;
        int cnt = 0;
        while(tmp != NULL)
        {
            cnt++;
            tmp = tmp -> next;
        }
        vector<ListNode*> res;
        tmp = root;
        for(int i = 0; i < k; i++)
        {
            int num = i < (cnt%k) ? (cnt/k+1) : cnt/k;
            if(num == 0)
            {
                res.push_back(NULL);
                continue;
            }
            ListNode* curstart = tmp;
            ListNode* curend = tmp;
            for(int j = 0; j < num-1; j++)
            {
                curend = curend->next;
            }
            if(curend->next != NULL)
                tmp = curend->next;
            curend->next = NULL;
            res.push_back(curstart);
        }
        return res;
    }
};