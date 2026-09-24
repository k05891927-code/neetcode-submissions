class MinStack {
public:
    stack<pair<int,int>>st; //number,min
    MinStack() {
        
        st.push({0,INT_MAX}); // k, mini till now 
    }
    
    void push(int val) {
        st.push({val,min(val,st.top().second)});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
