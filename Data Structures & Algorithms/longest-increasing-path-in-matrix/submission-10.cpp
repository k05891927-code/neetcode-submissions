class Solution {
public:

    int LIP(int i,int j,int prevnum,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size() || matrix[i][j]<=prevnum){
            return 0;
        }//i cant use this invalid cell in LIP

        if(dp[i][j]!=-1){return dp[i][j];}

        int tmp=matrix[i][j];
        matrix[i][j]=-1;
       
        int ans=0;

        vector<vector<int>>nei={{0,1},{0,-1},{1,0},{-1,0}};

        for(auto it:nei){
            if(i+it[0]>=0 && j+it[1]>=0 && i+it[0]<matrix.size() && j+it[1]<matrix[0].size() && tmp<matrix[ i+it[0]][j+it[1] ])
            ans=max( ans, LIP(i+it[0],j+it[1],tmp,matrix,dp)  );
        }
        
        matrix[i][j]=tmp;

        return dp[i][j]=1+ans;

    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int maxlen=1;
        
        int maxele = INT_MIN;
        for (auto row : matrix) {
            maxele = max(maxele, *max_element(row.begin(), row.end()));
        }

        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1));

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                int currLIP= LIP(i,j,-1,matrix,dp);
                cout<<currLIP<<endl;
                maxlen=max(maxlen,currLIP);
            }
        }
        return maxlen;

    }
};
