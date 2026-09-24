class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left=0,right=matrix.size()*matrix[0].size()-1;
        int row=matrix.size(),col=matrix[0].size();
        while(left<=right){
            int mid=(left+right)/2;
            int r=mid/col,c=mid%col;
            if(matrix[r][c]==target){
                return true;
            }
            else if(matrix[r][c]<target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return false;

    }
};
