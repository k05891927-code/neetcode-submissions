class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        //find place to stock maximum gas supply

        vector<int>diff(cost.size(),0);
        for(int i=0;i<cost.size();i++){
            diff[i]=gas[i]-cost[i];
        }


        int n=gas.size();
        for(int i=0;i<n;i++){
            diff.push_back(diff[i]);
        }//made double size

        int s=0,e=0;
        int sum=0;
        while(e<diff.size()){
            if(sum+diff[e]>=0){
                sum=sum+diff[e];
                e++;
            }
            else if(sum+diff[e]<0){
                sum=0;//eth is -ve 
                e++;
                s=e;
            }
            if(e-s==gas.size()){
                break;
            }
        }
        return (e-s)==gas.size()? s : -1;

    }
};

// -1, 0, -1, 3

// -1, -1, 1