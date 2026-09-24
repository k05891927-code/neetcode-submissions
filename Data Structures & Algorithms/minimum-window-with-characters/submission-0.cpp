class Solution {
public:

    bool validsubstr(map<char,int>&m1,map<char,int>&m2){
        for(auto it:m2){
            char ch=it.first;int count=it.second;
            if(m1[ch]<count){
                return 0; 
            }
        }
        return 1;
    }

    string minWindow(string s, string t) {
        //if not valid, keep moving right hoping to get valid
        //if valid, shrink windlow from left, hoping to keep valid with smaller size

        int n1=s.size(),n2=t.size();
        if(n1<n2){return "";}

        map<char,int>m1,m2;

        for(auto it:t){
            m2[it]++;
        }

        int left=0,right=0;
        int minlen=100000;int ansl=-1,ansr=-1; 

        while(right<n1){
            
            m1[s[right]]++;
            while(validsubstr(m1,m2)){
                if(right-left+1 < minlen){
                    minlen= right-left+1;

                    ansl=left;ansr=right;
                }
                m1[s[left]]--;
                left++;
            }

            right++;
        }

        if(ansl==-1){return "";}
        string ansSt="";
        for(int i=ansl;i<=ansr;i++){ansSt+=s[i];}
        return ansSt;

    }
};
