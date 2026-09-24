class Solution {
public:
    int timetaken(vector<int>& piles, int k){
        int time=0;
        for(auto it:piles){
            time+=ceil((double)it/k);
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        int ans;

        while(left<=right){
            int mid=(left+right)/2;

            if(timetaken(piles,mid)>h){
                left=mid+1;
            }
            else{
                ans=mid;
                right=mid-1;
            }

        }
        return ans;

    }
};
