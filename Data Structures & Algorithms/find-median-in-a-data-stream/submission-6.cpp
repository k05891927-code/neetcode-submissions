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
        while(abs((int)maxheap.size() -(int)minheap.size() )>1 ){

            if(maxheap.size()< minheap.size())
            {  maxheap.push(minheap.top());minheap.pop();  }
               
            else
            {minheap.push(maxheap.top());maxheap.pop();}
                
        }

    }
    
    double findMedian() {

        if (maxheap.size() > minheap.size())
            return maxheap.top();
        else if (minheap.size() > maxheap.size())
            return minheap.top();
        else
            return (maxheap.top() + minheap.top()) / 2.0;
    }
};
