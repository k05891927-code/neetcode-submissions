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

    TreeNode* getsubtreeroot(TreeNode* subtreeroot,int val){
        if(subtreeroot==NULL){return NULL;}

        if(subtreeroot->val==val){
            return subtreeroot;
        }

        TreeNode*l= getsubtreeroot(subtreeroot->left,val) ;
        if(l!=NULL){
            return l;
        }
        TreeNode*r= getsubtreeroot(subtreeroot->right,val); 
        return r;
        

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
        subtreeroot= getsubtreeroot(root,subRoot->val);
        if(subtreeroot==NULL){return false;}// no subtreeroot matching node found

        
        return checksame(subtreeroot,subRoot);
    }
};
