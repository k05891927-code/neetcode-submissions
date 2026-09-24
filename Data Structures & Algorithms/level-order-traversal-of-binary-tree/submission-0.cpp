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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL){return ans;}

        queue<TreeNode*>q;
        q.push(root);
        int size=1;
        vector<int>tmp;
        while(!q.empty()){
            auto front= q.front();
            tmp.push_back(front->val);
            q.pop();

            if(front->left){q.push(front->left);}
            if(front->right){q.push(front->right);}

            size--;
            if(size==0){
                ans.push_back(tmp);
                size=q.size();
                tmp.clear();
            }
        }
        return ans;

    }
};
