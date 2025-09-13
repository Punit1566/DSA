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
    int solve(TreeNode* root, int &maxSum){
        if(root==NULL){
            return 0;
        }
        int left=solve(root->left,maxSum);
        int right=solve(root->right,maxSum);
        int type1=root->val+left+right;
        int type2=max(left,right)+root->val;
        int type3=root->val;
        maxSum=max(maxSum,max(type1,max(type2,type3)));
        return max(type2,type3);

    }
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        return max(maxSum,solve(root,maxSum));
        
    }
};