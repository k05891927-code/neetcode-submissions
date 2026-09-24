class Solution {
public:

    int Gparent(int node,vector<int>&parent){
        if(parent[node]==node){
            return node;
        }
        else{
            return parent[node]=Gparent(parent[node],parent);
        }
    }
    void dsunion(int node1,int node2,vector<int>&siz,vector<int>&parent){
        int par1= Gparent(node1,parent);
        int par2= Gparent(node2,parent);

        if(par1==par2){
            return; //same connected componente
        }
        if(siz[node1]<=siz[node2]){
            siz[node2]+=siz[node1];
            parent[node1]=node2;
        }
        else{
            siz[node1]+=siz[node2];
            parent[node2]=node1;
        }

    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector<int>parent(edges.size()+1,0);
        for(int i=0;i<parent.size();i++){parent[i]=i;}
        vector<int>siz(edges.size()+1,1);

        for(auto it:edges){
            cout<<it[0]<<" "<<Gparent(it[0],parent)<<" , "<<it[1]<<" "<<Gparent(it[1],parent)<<endl;
            if(Gparent(it[0],parent)!=Gparent(it[1],parent )){
                dsunion(it[0],it[1],siz,parent);
            }
            else{
                return it;
            }
            cout<<it[0]<<" "<<Gparent(it[0],parent)<<" , "<<it[1]<<" "<<Gparent(it[1],parent)<<endl<<endl;;
            
        }
        return {};

    }
};
