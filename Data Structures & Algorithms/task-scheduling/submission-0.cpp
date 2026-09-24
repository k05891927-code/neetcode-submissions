class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>v(26,0);
        vector<int>canstartat(26,0);
        for(auto it:tasks){
            v[it-'A']++;
        }
        sort(v.rbegin(),v.rend());//descending , most repeting should be done at start

        int time=0;
        int totalelements=tasks.size();
        while(totalelements>0){
            
            for(int i=0;i<26;i++){
                if(canstartat[i]<=time && v[i]>0){
                    //do this in this time
                    canstartat[i]+= (n+1); //this can happen now at or after
                    v[i]--; //done with one job of this
                    totalelements--;

                    break; //can do only one at this time
                }
            }

            time++;
            
        }
        return time;

    }
};
