class Solution {
public:
    int reverse(int x) {
        
        string st = to_string(llabs((long long)x));//abs-> llabs
        long long signeg= (x<0)? 1:0;
        std::reverse(st.begin(),st.end());
        long long num= stoll(st);

        if(signeg==1){
            if(num<INT_MIN){
                return 0;
            }
        }
        else{
            if(num>INT_MAX){
                return 0;
            }
        }

        if(signeg){
            num*=-1;
        }

        return num;

    }
};
