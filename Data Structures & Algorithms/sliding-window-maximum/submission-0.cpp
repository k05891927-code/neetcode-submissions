class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int>ms;
        for(int i=0;i<k;i++){
            ms.insert(nums[i]);
        }
        vector<int>ans={*ms.rbegin()}; //insert max from first window
        for(int i=k;i<nums.size();i++){//move right pointer
            ms.insert(nums[i]);
            
            auto it= ms.find(nums[i-k]);//remove left elelmt
            ms.erase(it);

            ans.push_back(*ms.rbegin());
            
        }

        return ans;
    }
};
