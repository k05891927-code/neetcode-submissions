class KthLargest {
public:
    priority_queue<int,vector<int>,greater<>>pq;int K=-1;
    KthLargest(int k, vector<int>& nums) {
        //kth largest
        // min heap of k size
        K=k;
        for(auto it:nums){
            pq.push(it);
            if(pq.size()>k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>K){
            pq.pop();
        }
        return pq.top();
    }
};

