class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int>m;
        for(int i=0;i<s.size();i++){ //last index of occurance
            m[s[i]]=i;
        }
        vector<int>ans;

        int start=0,end=0;
        int gotill=0;
        while(end<s.size()){

            if(m[s[end]]>end){
                gotill=max(gotill,m[s[end]]);
                end++;
            }
            else if(end<gotill){
                end++;
            }
            //end string at this end
            else{
                ans.push_back(end-start+1);
                end++;
                start=end;
                gotill=start;
            } 


        }
        return ans;
    }
};
