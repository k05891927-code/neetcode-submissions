class Solution {
public:

    int solve(int ind,int amount, vector<int>& coins){
        if(ind==0){
            if(amount%coins[ind]==0){
                return  amount/coins[ind];
            }
            else{
                return INT_MAX;
            }
        }

        //nottake
        int nottake= solve(ind-1,amount,coins);
        //take
        int take=INT_MAX;
        if(amount>=coins[ind]){
            int curr= solve(ind,amount-coins[ind],coins);
            if(curr!=INT_MAX){ //otherwise remain int_max
                take= 1+ curr;
            }
        }
        return min(take,nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans=solve(coins.size()-1,amount,coins);
        return ans==INT_MAX? -1 : ans;
    }
};
