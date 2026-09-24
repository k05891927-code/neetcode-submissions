class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ek=0;
        set<vector<int>>s;
    
        for(int i=0;i<n;i++){
            int j=i+1,k=n-1;

            while(j<k){
                if(nums[i]+nums[j]+nums[k]==ek){
                    s.insert({nums[i],nums[j],nums[k]});
                    j++;k--;
                }
                else if(nums[i]+nums[j]+nums[k]<ek){
                    j++;
                }
                else{
                    k--;
                }
            }

        }
        vector<vector<int>> a;
        for(auto it:s){
            a.push_back(it);
        }
        return a;

    }
};
