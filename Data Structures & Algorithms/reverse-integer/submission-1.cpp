class Solution {
public:
    int reverse(int x) {
        
        string st=to_string(abs(x));
        int signeg= (x<0)? 1:0;
        std::reverse(st.begin(),st.end());
        long long num= stoll(st);

        if(signeg==1){
            // string mins=to_string(abs(INT_MIN));
            // if(st >mins && st.size()==mins.size()){
            //     return 0;
            // }
            if(num<INT_MIN){
                return 0;
            }
        }
        else{
            string maxs=to_string(abs(INT_MAX));
            if(st >maxs && st.size()==maxs.size() ){
                return 0;
            }
        }

        if(signeg){
            num*=-1;
        }

        return num;

    }
};
