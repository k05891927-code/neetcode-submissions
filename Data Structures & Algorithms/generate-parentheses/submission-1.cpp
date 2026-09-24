class Solution {
public:

    void solve(int open,int closed,string& st,vector<string>&ans,int n){
        if(open==n && closed==n){   
            ans.push_back(st);
            return ;
        }
        
        //at this index
        //add open 
        if(open<n){
            st.push_back('(');
            solve(open+1,closed,st,ans,n);
            st.pop_back();
        }

        //add closed
        if(open>closed){
            st.push_back(')');
            solve(open,closed+1,st,ans,n);
            st.pop_back();
        }


    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string curr="";
        int open=0,closed=0;
        solve(open,closed,curr,ans,n);
        return ans;

    }
};
