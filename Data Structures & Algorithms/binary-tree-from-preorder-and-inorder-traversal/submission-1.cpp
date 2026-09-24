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
    map<int,int>m;
    void buildmap(vector<int>& inorder){
        int ind=0;
        for(auto it:inorder){
            m[it]=ind;
            ind++;
        }
    }

    TreeNode* maketree(vector<int>&inorder,vector<int>& preorder, int ins, int inl, int pres, int prel ){

        if(ins>inl || pres>prel || ins<0 || pres<0 || inl>=preorder.size()  ||prel>=preorder.size() ){return NULL;}

        TreeNode* curr= new TreeNode(preorder[pres]);
        int indxinorder= m[preorder[pres]];
        int leftelement = indxinorder - ins;

        curr->left=maketree(inorder,preorder, ins, indxinorder-1, pres+1, pres+leftelement );
        curr->right=maketree(inorder,preorder, indxinorder+1, inl, pres+leftelement+1, prel);

        return curr;        

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         //element,index
        buildmap(inorder);
        int size=inorder.size();
        TreeNode* root= maketree(inorder,preorder, 0, size-1, 0, size-1 ); //inorder ind, preorder ind

        return root;

    }
};
