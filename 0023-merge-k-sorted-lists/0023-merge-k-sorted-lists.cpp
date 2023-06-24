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
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto head: lists) {
            ListNode *temp = head;
            while(temp) {
                pq.push(temp->val);
                temp = temp->next;
            }
        }

        return createList(pq);
    }
    ListNode* createList(priority_queue<int, vector<int>, greater<int>> pq) {
        if(pq.size() == 0) return NULL;

        ListNode* top =  new ListNode(pq.top());
        pq.pop();
        top->next = createList(pq);
        return top;
    }
};