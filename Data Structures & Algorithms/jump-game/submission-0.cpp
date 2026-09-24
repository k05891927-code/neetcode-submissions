class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxpossible=0;
        for(int i=0;i<nums.size();i++){
            if(i>maxpossible){
                return false;
            }
            maxpossible= max(maxpossible,nums[i]+i);
        }
        return true;
    }
};
