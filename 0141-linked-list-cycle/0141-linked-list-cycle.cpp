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
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)
            return 0;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(slow && fast) {
            fast = fast -> next;
            if(fast)
                fast = fast -> next;
            slow = slow -> next;
            if(slow == fast)
                return 1;
        }
        return 0;
    }
};