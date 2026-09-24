class Solution {
public:

    
    void solve(int ind,vector<int>& nums,vector<int>&curr,set<vector<int>>&ans, int target){
        if(ind==nums.size()){
            if(target==0){
                ans.insert(curr);
            }
            return;
        }

        if(nums[ind]<=target){
            //take
            curr.push_back(nums[ind]);
            solve(ind+1,nums,curr,ans,target-nums[ind]);
            curr.pop_back();
        }
        solve(ind+1,nums,curr,ans,target);

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>>ans;
        vector<int> curr;
        int ind=0;
        solve(ind,candidates,curr,ans,target);

        vector<vector<int>>finans(ans.begin(),ans.end());
        // for(auto it:ans){
        //     finans.push_back(it);
        // }
        return finans;
    }
};

