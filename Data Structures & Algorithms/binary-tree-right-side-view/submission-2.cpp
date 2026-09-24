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

    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL){return ans;}

        // map<int,int>m;
        // int hei=0;

        queue<TreeNode*>q;
        q.push(root);
        int size=1;

        while(!q.empty()){
            auto front=q.front();
            q.pop();
            // m[hei]=front->val;

            if(front->left){q.push(front->left);}
            if(front->right){q.push(front->right);}

            size--;
            if(size==0){
                ans.push_back(front->val);
                size=q.size();
                // hei++;
            }
        }

        // for(auto it:m){
        //     ans.push_back(it.second);
        // }
        return ans;

    }
};
