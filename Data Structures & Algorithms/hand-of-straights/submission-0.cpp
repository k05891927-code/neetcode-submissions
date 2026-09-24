class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0){return false;}

        int total=hand.size();
        vector<int>v(1001,0);
        for(auto it:hand){v[it]++;}
        int curstart=0;
        while(total>0){

            while(v[curstart]==0){
                curstart++;
            }
            //curstart is non-zero, start from it
            for(int i=0;i<groupSize;i++){
                if(v[curstart+i]==0){ return false;} //cant make group

                else{
                    v[curstart+i]--;
                    total--;
                }
            }

        }
        return true;

    }
};
