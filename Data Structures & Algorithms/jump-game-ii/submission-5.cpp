class Solution {
public:
    int jump(vector<int>& nums) {
        int maxpossible=nums[0];
        int jump=1;
        int maxi=-1;
        if(nums.size()==1){return 0;}
        for(int i=1;i<nums.size();i++){
            if(i==nums.size()-1){
                break;
            }
            maxi=max(maxi,nums[i]+i);
            if(i==maxpossible){
                jump++;
                maxpossible=maxi;

            }
            
        }

        return jump;
    }
};
