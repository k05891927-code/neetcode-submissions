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

        int ans=1;
        for(int i=1;i<v.size();i++){
            if(v[i-1][1]>v[i][1]){
                ans++;
            }
        }
        return ans;

    }
};

// 0,  1,  4, 7
// 1,  2,  2, 1

// 10, 4.5,3, 3 


// 10, 9 , 1,2,5 , 2,5,5, 2,2,3 , 1  