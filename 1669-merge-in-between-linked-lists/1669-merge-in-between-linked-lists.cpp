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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* headptr = list1;
        ListNode* tailptr = list1;
        
        while(--a) 
            headptr = headptr -> next;
        // cout << headptr -> val;
        while(b--)
            tailptr = tailptr -> next;
        // cout << tailptr -> val;
        headptr -> next = list2;
        ListNode* ptr = list2;
        while(ptr -> next)
            ptr = ptr -> next;
        
        ptr -> next = tailptr -> next;
        return list1;
        
        
        // return nullptr;
    }
};