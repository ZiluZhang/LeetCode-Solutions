// Intersection of Two Linked Lists

// 把较长的list缩短，两个一样长了，从头开始遍历，相等的地方就是起点
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // if(!headA || !headB) return NULL;
        int len1 = getLength(headA);
        int len2 = getLength(headB);
        if(len1 < len2) {
            for(int i = len1; i < len2; i++)
                headB = headB->next;
        } else {
            for(int i = len2; i < len1; i++)
                headA = headA->next;
        }
        while(headA && headB && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
    
    int getLength(ListNode* head) {
        int cnt = 0;
        while(head) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
};

// 一个list遍历到头就继续遍历另一个，这样一定会相遇，因为都遍历lenA+lenB，相遇点就是起点
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode* a = headA;
        ListNode* b = headB;
        while(a != b) {
            a = a ? a->next: headB;
            b = b ? b->next: headA;
        }
        return a;
    }
};