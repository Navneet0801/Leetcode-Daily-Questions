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
    
    pair<int,int> diameterFast(TreeNode* root){
        if(root == nullptr){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);
        
        int opt1 = left.first;
        int opt2 = right.first;
        int opt3 = left.second + right.second;
        
        pair<int,int> ans;
        ans.first = max(opt1 , max(opt2 , opt3));
        ans.second = max(left.second , right.second) + 1;
        
        return ans;
    }
        
    int diameterOfBinaryTree(TreeNode* root) {
//         if(root == nullptr){
//             return 0;
//         }
        
//         int opt1 = diameterOfBinaryTree(root->left);
//         int opt2 = diameterOfBinaryTree(root->right);
//         int opt3 = height(root->left) + height(root->right);
        
//         int ans = max(opt1 , max(opt2 , opt3));
//         return ans;
        
        return diameterFast(root).first;
    }
};