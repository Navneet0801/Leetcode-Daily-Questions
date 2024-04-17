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
    string ans = "";
    char nth_letter(int n) {
        return "abcdefghijklmnopqrstuvwxyz"[n];
    }
    void solve(TreeNode* root, string temp) {
        if(!root) 
            return;
        
        char ch = nth_letter(root -> val);
        temp.push_back(ch);
        if(!root->left && !root->right) {
            string temp1 = temp;
            reverse(temp1.begin(), temp1.end());
            if(ans.empty() || temp1 < ans)
                ans = temp1;
            return;
        }
        
        solve(root -> left, temp);
        solve(root -> right, temp);
    }
    string smallestFromLeaf(TreeNode* root) {
        string temp = "";
        solve(root, temp);
        return ans;
    }
};