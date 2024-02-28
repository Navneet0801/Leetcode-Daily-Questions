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
    int ans = 0;
    int maxLvl = 0;
    void solve(TreeNode* root, int lvl) {
        if(!root)
            return;
        
        if(maxLvl < lvl) {
            ans = root -> val;
            maxLvl = lvl;
        }
        
        solve(root -> left, lvl+1);
        solve(root -> right, lvl+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        if(!root -> left && !root -> right)
            return root -> val;
        
        solve(root, 0);
        return ans;
    }
};