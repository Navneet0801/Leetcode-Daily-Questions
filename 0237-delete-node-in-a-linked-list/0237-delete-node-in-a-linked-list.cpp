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
    void deleteNode(ListNode* node) {
        ListNode* ptr = node;
        ListNode* next = nullptr;
        
        while(ptr) {
            next = ptr -> next;
            ptr -> val = next -> val;
            
            if(next -> next == nullptr) {
                ptr -> next = nullptr;
                break;
            }
            ptr = ptr -> next;
        }
    }
};