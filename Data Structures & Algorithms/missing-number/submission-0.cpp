class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum= ((long long)nums.size()*((long long)nums.size()+1))/2;

        for(auto it:nums){
            sum-=it;
        }
        return sum;
    }
};
