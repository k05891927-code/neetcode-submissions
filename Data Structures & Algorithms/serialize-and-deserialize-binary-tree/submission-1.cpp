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

class Giveparts{
    public:
    string st;
    int index=0;
    Giveparts(string st){
        this->st=st;
    }

    string next(){
        string ans="";
        while(st[index]!=',' && index<st.size()){
            ans+=st[index];
            index++;
        }
        index++;
        return ans;
    }

};


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string st="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto front= q.front();
            q.pop();

            if(front==NULL){
                st+="#,";
            }
            else{
                st+=to_string(front->val);
                st+=",";
                q.push(front->left);
                q.push(front->right);
            }
        }
        return st;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        Giveparts obj(data);
        // string nex= obj.next();

        TreeNode* root=NULL;queue<TreeNode* >q;
        string curr= obj.next();
        if(curr!="#"){root = new TreeNode(stoi(curr));q.push(root);}

        
        while(!q.empty()){
            TreeNode*currroot= q.front();q.pop();
            curr= obj.next();
            if(curr!="#"){
                TreeNode* left=new TreeNode(stoi(curr));
                currroot->left=left;
                q.push(left);
            }

            curr= obj.next();
            if(curr!="#"){
                TreeNode* right=new TreeNode(stoi(curr));
                currroot->right=right;
                q.push(right);
            }
        }
        return root;
    }
};
