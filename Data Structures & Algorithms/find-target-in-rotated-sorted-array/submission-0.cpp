class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ind=-1;
        int start=0,end=nums.size()-1;

        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[start]<nums[mid]){//left is sorted
                if(target<nums[mid] && target>=nums[start]){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            else{//right is sorted
                if(target>nums[mid] && target<=nums[end]){
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
