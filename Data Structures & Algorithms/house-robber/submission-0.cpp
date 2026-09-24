class Solution {
public:

    int solve(int ind,vector<int>&nums){
        if(ind>=nums.size()){
            return 0;
        }

        int nottake= solve(ind+1,nums);
        int take= nums[ind]+ solve(ind+2,nums);

        return max(nottake,take);


    }


    int rob(vector<int>& nums) {
        
        int ans=solve(0,nums);
        return ans;

    }
};
