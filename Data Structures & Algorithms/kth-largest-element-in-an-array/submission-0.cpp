class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //min heap with k size
        priority_queue<int,vector<int>,greater<>>pq;
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }
        for(int i=k;i<nums.size();i++){
            pq.push(nums[i]);//k+1 largest element
            pq.pop();
        }
        return pq.top();
    }
};
