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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0)
            return NULL;
        vector<int> nums;
        for(int i = 0; i < k; i++)
        {
            ListNode* tmp = lists[i];
            while(tmp != NULL)
            {
                nums.push_back(tmp->val);
                tmp = tmp->next;
            }
        }
        sort(nums.begin(), nums.end());
        int len = nums.size();
        ListNode* res = new ListNode(-1);
        ListNode* tmp = res;
        for(int i = 0; i < len; i++)
        {
            tmp->next = new ListNode(nums[i]);
            tmp = tmp->next;
        }
        return res->next;
    }
};