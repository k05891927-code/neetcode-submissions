// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>>ans;
//         sort(nums.begin(),nums.end());
//         ans.push_back(nums);
//         while(next_permutation(nums.begin(),nums.end())){
//             ans.push_back(nums);
//         }
//         return ans;
//     }

// };

void solve(int ind,vector<int>&nums,vector<int>&curr,vector<vector<int>>&ans ){
    if(ind==nums.size()){
        ans.push_back(curr);
        return;
    }

    for(int i=ind;i<nums.size();i++){
        swap(nums[ind],nums[i]);
        curr.push_back(nums[ind]);
        solve(ind+1,nums,curr,ans);
        curr.pop_back();
        swap(nums[ind],nums[i]);
    }

}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        solve(0,nums,curr,ans);
        return ans;
    }

};
