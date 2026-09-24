class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        st.push(stoi(tokens[0]));
        for(int i=1;i<tokens.size();i+=2){
            int num1=st.top();
            int num2=stoi(tokens[i]);

            string op=tokens[i+1];
            int ans=0;
            if(op=="+"){ans=num1+num2;}
            else if(op=="-"){ans=num1-num2;}
            else if(op=="*"){ans=num1*num2;}
            else if(op=="/"){ans=num1/num2;}

            st.push(ans);
        }
        return st.top();
    }
    
};
