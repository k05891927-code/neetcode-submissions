class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1=nums1.size()-1;
        int n2=nums2.size()-1;

        if(n1>n2){
            return findMedianSortedArrays(nums2,nums1);
        }

        int total = n1+n2;
        
        int start=0,end=n1;
        // indx and after in right excluded part 
        //left part are before  
        while(start<=end){
            int mid1=(start+end)/2;
            int mid2=total - mid1;

            int l1= mid1<0? INT_MIN : nums1[mid1-1];
            int l2= mid2<0? INT_MIN : nums2[mid2-1];
            int r1= mid1>n1? INT_MAX: nums1[mid1];
            int r2= mid2>n2? INT_MAX: nums2[mid2];

            if(l1>r2){
                end=mid1-1;
            }
            else if(l2>r1){
                start=mid+1;
            }
            else{ //(l1<=r2) && (l2<=r1)
                if(total%2){
                    return min(nums1[mid1],nums2[mid2]);
                }
                else{
                    return (nums1[mid1]+nums2[mid2])/2;
                }
            }

        }

    } 
};
