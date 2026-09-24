class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ind=-1;
        int left=0,right=nums.size()-1;

        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[left]<nums[mid]){//left is sorted
                if(target<nums[mid] && target>=nums[left]){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            else{//right is sorted
                if(target>nums[mid] && target<=nums[right]){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
        }
        return -1;

    }
};
