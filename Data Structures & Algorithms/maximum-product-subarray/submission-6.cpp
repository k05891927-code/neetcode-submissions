class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int carymin=nums[0];
        int carymax=nums[0];
        int ans=nums[0];

        for(int i=1;i<nums.size();i++){
            int oldmax=carymax;
            int oldmin=carymin;
            carymax=max({oldmax*nums[i],oldmin*nums[i],nums[i]});
            carymin=min({oldmax*nums[i],oldmin*nums[i],nums[i]});

            ans=max(carymax,ans);
            
        }
        return ans;

    }
};
