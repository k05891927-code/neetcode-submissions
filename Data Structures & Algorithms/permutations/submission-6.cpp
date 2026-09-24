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

void solve(int ind,vector<int>&nums,vector<vector<int>>&ans ){
    if(ind==nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i=ind;i<nums.size();i++){
        swap(nums[ind],nums[i]);
        solve(ind+1,nums,ans);
        swap(nums[ind],nums[i]);
    }

}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(0,nums,ans);
        return ans;
    }

};
