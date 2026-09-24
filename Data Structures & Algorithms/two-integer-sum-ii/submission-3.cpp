class Solution {
public:
    vector<int> twoSum(vector<int>& numb, int target) {
        sort(numb.begin(),numb.end());

        int i=0;int j=numb.size()-1;
        while(i<j){
            if(numb[i]+numb[j]==target){
                return {i+1,j+1};
            }
            else if(numb[i]+numb[j]<target){
                i++;
            }
            else{
                j--;
            }
        }
        return {};

    }
};
