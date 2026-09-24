class KthLargest {
public:
    priority_queue<int,vector<int>,greater<>>pq;
    KthLargest(int k, vector<int>& nums) {
        //kth largest
        // min heap of k size
        
        for(auto it:nums){
            pq.push(it);
            if(pq.size()>k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);

        pq.pop();

        return pq.top();
    }
};

