class Solution {
public:

    vector<int>NSE(vector<int>&heights){
        stack<int>s;
        vector<int>ans(heights.size(),-1);
        for(int i=heights.size()-1;i>=0;i--){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            ans[i]= s.empty()? heights.size() : s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int>PSE(vector<int>&heights){
        stack<int>s;
        vector<int>ans(heights.size(),-1);
        for(int i=0; i<heights.size();i++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            ans[i]= s.empty()? -1 : s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        
        vector<int>nse,pse; //next smallest element //previous smallest element

        nse= NSE(heights);//give index of next smallest(strictly) element
        pse= PSE(heights);

        int ans=0;
        for(int i=0;i<heights.size();i++){
            ans= max(ans, heights[i]*((nse[i]-1)-(pse[i]+1)+1)   );
        }

        return ans;

    }
};
