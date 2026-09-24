class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxi=0;
        int n=heights.size();
        int i=0,j=n-1;

        while(i<j){
            maxi=max(maxi,min(heights[i],heights[j])*(j-i)  );
            if(heights[i]<heights[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxi;

    }
};
