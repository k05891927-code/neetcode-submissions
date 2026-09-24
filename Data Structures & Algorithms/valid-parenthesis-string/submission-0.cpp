class Solution {
public:
    bool checkValidString(string s) {

        //left to right
        //are there sufficiently more open bracket to close all
        int open=0;
        for(auto ch: s){
            if(ch=='(' || ch=='*'){
                open++;
            }
            else{
                if(open<=0){
                    return false;
                }
                else{
                    open--;
                }
            }
        }
        open=0;
        reverse(s.begin(),s.end());
        for(auto &it:s){
            if(it=='('){
                it=')';
            }
            else if(it==')'){
                it='(';
            }
        }
        for(auto ch: s){
            if(ch=='(' || ch=='*'){
                open++;
            }
            else{
                if(open<=0){
                    return false;
                }
                else{
                    open--;
                }
            }
        }
        return true;

    }
};
