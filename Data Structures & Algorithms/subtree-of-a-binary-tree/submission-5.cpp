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
    vector<TreeNode*>v;
    void getsubtreeroot(TreeNode* subtreeroot,int val){
        if(subtreeroot==NULL){return ;}

        if(subtreeroot->val==val){
            v.push_back(subtreeroot);
        }

        getsubtreeroot(subtreeroot->left,val) ;
        getsubtreeroot(subtreeroot->right,val); 
        
    }

    bool checksame(TreeNode* subtreeroot,TreeNode* subRoot){
        if(subtreeroot==NULL &&subRoot==NULL){
            return true;
        }
        if(subtreeroot==NULL || subRoot==NULL){
            return false;
        }

        return ((subtreeroot->val==subRoot->val) && checksame(subtreeroot->left,subRoot->left) && checksame(subtreeroot->right,subRoot->right) );
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        TreeNode* subtreeroot=NULL;
        getsubtreeroot(root,subRoot->val);
        
        for(auto subtreeroot:v){
            if(checksame(subtreeroot,subRoot)){
                return true;
            }
        }
        return false;
    }
};
