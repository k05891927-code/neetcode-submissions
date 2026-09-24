class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++){
            string ch=tokens[i];
            if(ch=="+" || ch=="-" || ch == "/" || ch== "*"){
                int num2=st.top();st.pop();
                int num1=st.top();st.pop();
                int ans=0;

                if(ch=="+"){ans=num1+num2;}
                else if(ch=="-"){ans=num1-num2;}
                else if(ch=="*"){ans=num1*num2;}
                else if(ch=="/"){ans=num1/num2;}

                st.push(ans);
            }
            else{
                st.push(stoi(ch));
            }
        }

        return st.top();
    }
    
};
