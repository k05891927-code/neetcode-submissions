class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<float>>v; //position,time,speed

        for(int i=0;i<speed.size();i++){
            float spe=speed[i];
            float pos= position[i];
            float time= (target-pos)/spe;
            v.push_back({pos,time}); 
        }
        sort(v.begin(),v.end());//sort so cars aligned ass per postion on single lane highway

        int ans=0;
        float maxitime=0;
        for(int i=v.size()-1;i>=0;i--){
            if(v[i][1]>maxitime){
                ans++;
                maxitime=max(maxitime,v[i][1]);
            }
        }
        return ans;

    }
};

// 0,  1,  4, 7
// 1,  2,  2, 1

// 10, 4.5,3, 3 


// 10, 9 , 1,2,5 , 2,5,5, 2,2,3 , 1  ,1000

// 0, 2, 4
// 2, 3, 1
// 5, 2.6 , 6 