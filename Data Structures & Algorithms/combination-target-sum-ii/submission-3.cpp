class Solution {
public:

    
    void solve(int ind,vector<int>& nums,vector<int>&curr,vector<vector<int>>&ans, int target){
        if(ind==nums.size()){
            if(target==0){
                ans.push_back(curr);
            }
            return;
        }

        if(nums[ind]<=target){
            //take
            curr.push_back(nums[ind]);
            solve(ind+1,nums,curr,ans,target-nums[ind]);
            curr.pop_back();
        }
        int currid=ind;
        while(currid+1<nums.size() && nums[currid]==nums[currid+1]){
            currid++;
        }
        solve(currid+1,nums,curr,ans,target);

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        int ind=0;
        solve(ind,candidates,curr,ans,target);

        return ans;
    }
};

