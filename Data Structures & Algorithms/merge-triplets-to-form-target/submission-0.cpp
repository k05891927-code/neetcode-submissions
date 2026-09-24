class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        //firsdtly if triplet[i]>target, we cant it to make target
        //as once index will spike up after max operation

        int ind1=-1,ind2=-1,ind3=-1; //can i achive these indices of target

        for(auto it:triplets){
            if(it>target){
                continue;
            }
            else{
                if(it[0]==target[0]){
                    ind1=1;
                }
                if(it[1]==target[1]){
                    ind2=1;
                }
                if(it[2]==target[2]){
                    ind3=1;
                }
            }
        }
        if(ind1==1 && ind2==1 && ind3==1){
            return true;
        }
        else{
            return false;
        }

    }
};
