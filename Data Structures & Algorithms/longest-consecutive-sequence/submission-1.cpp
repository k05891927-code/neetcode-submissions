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

//honestly i found striver a2z hard array questions different, do go through speificly them (hard array), as here in neetcode for arrays, question pattern is not diverse
