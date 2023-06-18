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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t = headA, *tt = headB;
        bool test = true;
        while(t != tt) {
            t = t->next;
            tt = tt->next;
            if(!t) {
                if(!test) return NULL;
                test = false;
                t = headB;
            }
            if(!tt) tt = headA;
        }
        return tt;
    }
};