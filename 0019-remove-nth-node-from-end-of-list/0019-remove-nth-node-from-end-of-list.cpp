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
    int helper(ListNode* &head) {
        ListNode* ptr = head;
        int count = 0;
        while(ptr) {
            count++;
            ptr = ptr -> next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = helper(head);
        if(count <= 1)
            return nullptr;
        
        int target = count - n + 1;
        int i = 1;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(i != target) {
            prev = curr;
            curr = curr -> next;
            i++;
        }
        if(prev) {
            prev -> next = curr -> next;
            return head;
        }
        
        return curr -> next;
    }
};