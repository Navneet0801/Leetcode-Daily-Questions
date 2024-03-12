// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     void helper(vector<int> &arr) {
//         int n = arr.size();
//         for(int i=0; i<n;) {
//             int sum = arr[i];
//             int j = i+1;
//             bool flag = 0;
//             while(j < n) {
//                 if(sum == 0) {
//                     arr.erase(arr.begin()+i, arr.begin()+j);
//                     flag = 1;
//                     break;
//                 }
//                 sum += arr[j];
//                 j++;
//             }
//             if(flag)
//                 i = j;
//             else
//                 i++;
//         }
//     }
//     ListNode* removeZeroSumSublists(ListNode* head) {
//         vector<int> arr;
//         ListNode* ptr = head;
        
//         while(ptr) {
//             arr.push_back(ptr -> val);
//             ptr = ptr -> next;
//         }
//         // for(int i: arr)
//         //     cout << i << " ";
//         // cout << endl;
//         // cout << arr.size() << endl;
//         helper(arr);
//         // for(int i: arr)
//         //     cout << i << " ";
//         // cout << arr.size() << endl;
        
//         ListNode* newHead = new ListNode();
//         ListNode* curr = newHead;
//         for(int x: arr){
//             // if(x != 0){
//                 curr -> next = new ListNode(x);
//                 curr = curr->next;
//             // }
//         }
        
//         return newHead->next;
//     }
// };
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> arr;

        ListNode* ptr = head;

        while(ptr){
            arr.push_back(ptr->val);
            ptr = ptr->next;
        }
        
        int n = arr.size();
        int lo = 0, hi = 0;

        while(hi < n){
            int sum = arr[hi];
            lo = hi;

            while(lo > 0){
                sum += arr[--lo];
                if(sum == 0){
                    for(int i = lo; i <= hi; i++)
                        arr[i] = 0;

                    break;
                } 
            }
            hi++;
        }

        ListNode * newHead = new ListNode();
        ListNode * curr = newHead;
        for(int x: arr){
            if(x != 0){
                curr->next = new ListNode(x);
                curr = curr->next;
            }
        }
        
        return newHead->next;
    }
};