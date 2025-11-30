```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        priority_queue<ListNode*, vector<ListNode*>,
                       function<bool(ListNode*, ListNode*)>>
            pq([](ListNode* a, ListNode* b) { return a->val > b->val; });
        for (auto list : lists) {
            if (list)
                pq.push(list);
        }
        ListNode* tail = dummy;
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            tail->next = node;
            tail = node;
            if (node->next)
                pq.push(node->next);
        }
        return dummy->next;
    }
};
```