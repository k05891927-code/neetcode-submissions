class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0){return 0;}

        sort(nums.begin(),nums.end());

        int last=nums[0];
        int maxlen=1,cnt=1;
        for(int i=1;i<n;i++){
            if(nums[i]==last)
                continue;
            else if(nums[i]==last+1){
                last=nums[i];
                cnt++;
                maxlen=max(maxlen,cnt);
            }
            else{
                last=nums[i];
                cnt=1;
            }
        }
        return maxlen;
    }
};
