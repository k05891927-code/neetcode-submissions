class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<>>minheap;
    priority_queue<int>maxheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if( maxheap.empty() || (!maxheap.empty() && num<maxheap.top()))
            maxheap.push(num);
        else
            minheap.push(num);

        //balance out
        if(minheap.size()>maxheap.size()){
            maxheap.push(minheap.top());minheap.pop();
        }
        else{
            minheap.push(maxheap.top());maxheap.pop();
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
