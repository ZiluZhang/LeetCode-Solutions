// Merge k Sorted Lists
// 可以排序/分治/优先队列
// 优先队列运算符重载！头最小，要用>


// priority queue
struct cmp {
    bool operator () (ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return NULL;
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for(int i = 0; i < n; i++) {
            if(lists[i]) q.push(lists[i]);
        }
        ListNode* head = new ListNode(0);
        ListNode* tmp = head;
        while(!q.empty()) {
            ListNode* cur = q.top();
            q.pop();
            tmp->next = cur;
            if(cur->next) q.push(cur->next);
            tmp = tmp->next;
        }
        return head->next;
    }
};


// divide and conquer, merge 2 at one time
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return NULL;
        while(n > 1) {
            int k = (n + 1)/2; // 取的两个index相差k
            for(int i = 0; i < n / 2; i++) {
                lists[i] = merge2Lists(lists[i], lists[i+k]);
            }
            n = k;
        }
        return lists[0];
    }
    
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* tmp = head;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                tmp->next = l1;
                l1 = l1->next;
            }
            else {
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }
        while(l1) {
            tmp->next = l1;
            l1 = l1->next;
            tmp = tmp->next;
        }
        while(l2) {
            tmp->next = l2;
            l2 = l2->next;
            tmp = tmp->next;
        }
        return head->next;
    }
};

// sort numbers
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