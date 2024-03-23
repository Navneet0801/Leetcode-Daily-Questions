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
    void reorderList(ListNode* head) {
        if(!head || !head -> next)
            return;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next;
            if(fast)
                fast = fast -> next;
        }
        ListNode* ptr = head;
        while(ptr -> next != slow) 
            ptr = ptr -> next;
        ptr -> next = nullptr;
        
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        ListNode* next = nullptr;
        
        while(curr) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        ListNode* curr1 = head;
        ListNode* next1 = nullptr;
        ListNode* curr2 = prev;
        ListNode* next2 = nullptr;
        
        // while(head) {
        //     cout << head -> val << "-";
        //     head = head -> next;
        // }
        // cout << endl;
        // while(curr2) {
        //     cout << curr2 -> val << "-";
        //     curr2 = curr2 -> next;
        // }
        
        while(curr1 && curr2) {
            next1 = curr1 -> next;
            next2 = curr2 -> next;
            
            // cout << curr1 -> val << endl;
            curr1 -> next = curr2;
            curr1 = next1;
            if(curr1 == nullptr)
                break;
            
            // cout << curr2 -> val << endl;
            curr2 -> next = curr1;
            curr2 = next2;
            if(curr2 == nullptr)
                break;
        }
        // while(head) {
        //     cout << head -> val << "-";
        //     head = head -> next;
        // }
    }
};