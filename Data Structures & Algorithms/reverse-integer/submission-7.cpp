class Solution {
public:
    int reverse(int x) {
        
        string st = to_string(llabs((long long)x));//abs-> llabs
        long long signeg= (x<0)? 1:0;
        std::reverse(st.begin(),st.end());
        long long num= stoll(st);

        if(signeg==1){
            if(num*-1<INT_MIN){
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

// class Solution {
// public:
//     int reverse(int x) {
//         int ans = 0;

//         while (x != 0) {
//             int digit = x % 10;

//             if (ans > INT_MAX / 10 ||
//                 (ans == INT_MAX / 10 && digit > INT_MAX % 10)) {
//                 return 0;
//             }

//             if (ans < INT_MIN / 10 ||
//                 (ans == INT_MIN / 10 && digit < INT_MIN % 10)) {
//                 return 0;
//             }

//             ans = ans * 10 + digit;
//             x /= 10;
//         }

//         return ans;
//     }
// };
