class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxi=0;
        int n=heights.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                maxi=max(maxi, min(heights[i],heights[j])*(j-i)  );
            }
        }
        return maxi;
    }
};
