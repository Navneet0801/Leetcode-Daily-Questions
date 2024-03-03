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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* ptr = head;
        ListNode* ptr1 = head;
        int nodes = 0;
        while(ptr) {
            nodes++;
            ptr = ptr -> next;
        }
        // cout << nodes;
        ptr = head;
        int kth = nodes-k+1;
        int i = 1;
        
        while(i != k && ptr) {
            ptr = ptr -> next;
            i++;
        }
        // cout << ptr -> val << endl;
        
        i = 1;
        while(i != kth && ptr1) {
            ptr1 = ptr1 -> next;
            i++;
        }
        // cout << ptr1 -> val << endl;
        int temp = ptr -> val;
        ptr -> val = ptr1 -> val;
        ptr1 -> val = temp;
        
        return head;
    }
};