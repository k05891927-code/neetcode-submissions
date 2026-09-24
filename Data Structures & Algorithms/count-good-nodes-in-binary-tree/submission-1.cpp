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
    int ans=0;

    void helper(TreeNode* root,int maxi){
        if(root==NULL){return ;}

        ans += (root->val>=maxi)? 1:0 ;

        int newmaxi=max(maxi,root->val); //new,axi along path
        helper(root->left,newmaxi);
        helper(root->right,newmaxi);

    }

    int goodNodes(TreeNode* root) {
        if(root==NULL){return 0;}

        int maxi=root->val;
        ans=0;

        helper(root,maxi);

        return ans;


    }
};
