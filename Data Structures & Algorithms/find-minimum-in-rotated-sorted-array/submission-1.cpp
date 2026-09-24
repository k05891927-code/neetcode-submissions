class Solution {
public:
    int findMin(vector<int> &nums) {
        int mini=INT_MAX;

        int left=0,right=nums.size();
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[left]<nums[mid]){
                //left sorted
                mini=min(nums[left],mini);
                //search right
                left==mid+1;
            }
            else{
                //rifht is sorted
                mini=min(nums[mid],mini);//consider mini from right
                right=mid-1;
            }
        }
        return mini;

    }
};
