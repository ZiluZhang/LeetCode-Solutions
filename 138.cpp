// Copy List with Random Pointer
// 先把列表拷贝一份，同时存一个新旧指针的映射
// 然后再统一给random赋值

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        RandomListNode* res = new RandomListNode(head->label);
        RandomListNode* node = res;
        RandomListNode* cur = head->next;
        unordered_map<RandomListNode*, RandomListNode*> m;
        m[head] = res;
        while(cur) {
            RandomListNode* tmp = new RandomListNode(cur->label);
            node->next = tmp;
            m[cur] = tmp;
            node = node->next;
            cur = cur->next;
        }
        node = res;
        cur = head;
        while(node) {
            node->random = m[cur->random];
            cur = cur->next;
            node = node->next;
        }
        return res;
    }
};