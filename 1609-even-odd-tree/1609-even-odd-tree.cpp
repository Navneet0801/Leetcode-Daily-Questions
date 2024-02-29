/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool even = true;
        
        while(!q.empty()) {
            vector<int> temp;
            int size = q.size();
            for(int i=0; i<size; i++) {
                TreeNode* front = q.front();
                q.pop();
                temp.push_back(front -> val);
                
                if(front -> left)
                    q.push(front -> left);
                if(front -> right)
                    q.push(front -> right);
            }
            // for(int i: temp)
            //     cout << i << " ";
            // cout << endl;
            if(even) {
                if(temp[0]%2 == 0)
                    return 0;
                for(int i=1; i<temp.size(); i++) {
                    if(temp[i]%2 == 0 || temp[i] <= temp[i-1])
                        return 0;
                }
            }
            else {
                if(temp[0]%2 != 0)
                    return 0;
                for(int i=1; i<temp.size(); i++) {
                    if(temp[i]%2 != 0 || temp[i] >= temp[i-1])
                        return 0;
                }
            }
            // cout << even << endl;
            even = !even;
        }
        return 1;
    }
};