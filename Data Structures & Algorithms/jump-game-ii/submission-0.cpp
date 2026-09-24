class Solution {
public:
    int jump(vector<int>& nums) {
        int maxpossible=nums[0];
        int jump=1;
        int maxi=-1;
        for(int i=1;i<nums.size();i++){
            if(i==maxpossible){
                if(i==nums.size()-1){
                    break;
                }
                jump++;
                maxpossible=maxi;

            }
            maxi=max(maxi,nums[i]+i);
        }

        return jump;
    }
};
