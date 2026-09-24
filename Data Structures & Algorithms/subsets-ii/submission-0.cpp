class Solution {
public:

    void solve(int ind,vector<int>&curr,vector<vector<int>>&ans,vector<int>&nums){
        if(ind==nums.size()){
            ans.push_back(curr);
            return;
        }

        //take
        curr.push_back(nums[ind]);
        solve(ind+1,curr,ans,nums);
        curr.pop_back();

        //not take
        int ind2=ind;
        while(ind2+1<nums.size() && nums[ind2]==nums[ind2+1]){
            ind2++;
        }
        solve(ind2+1,curr,ans,nums);


    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());


        vector<vector<int>>ans;
        vector<int>curr;
        solve(0,curr,ans,nums);
        return ans;
    }
};
