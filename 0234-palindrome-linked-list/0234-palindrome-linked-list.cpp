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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *curr = head, *next;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode *turtle = head, *rabbit = head;
        while(rabbit && rabbit->next) {
            rabbit = rabbit->next->next;
            turtle = turtle->next;
        }
        
        turtle = reverseList(turtle);
        while(turtle) {
            if(head->val != turtle->val) return false;
            head = head->next;
            turtle = turtle->next;
        }
        
        return true;
    }
};