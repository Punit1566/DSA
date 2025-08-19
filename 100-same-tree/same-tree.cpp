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
    void solve2(TreeNode* r,vector<int>&ans2){
        if(r==NULL){
            ans2.push_back(INT_MAX);
            return;
        }
        ans2.push_back(r->val);
        solve1(r->left,ans2);
        solve1(r->right,ans2);

    }
    void solve1(TreeNode* l,vector<int>&ans1){
        if(l==NULL){
           ans1.push_back(INT_MAX);
           return;
        }
        ans1.push_back(l->val);
        solve1(l->left,ans1);
        solve1(l->right,ans1);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)return true;
        
        vector<int>ans1,ans2;
        solve1(p,ans1);
        solve2(q,ans2);

        if(ans1==ans2){
            return true;
        }return false;
    }
};