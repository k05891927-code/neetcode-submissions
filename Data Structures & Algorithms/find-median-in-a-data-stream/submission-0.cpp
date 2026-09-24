class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<>>minheap;
    priority_queue<int>maxheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minheap.push(num);
        if(maxheap.size()+2 <= minheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if((maxheap.size()+ minheap.size())%2==0 ){
            return ((float)maxheap.top()+ minheap.top())/2;
        }
        else{
            return minheap.top();
        }
    }
};
