class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        if(n1>n2){return false;}
        
        unordered_map<char,int>check,m;
        //intialize all 0
        for(int i=0;i<26;i++){
            m['a'+i]=0;
            check['a'+i]=0;
        }

        for(char ch:s1){
            check[ch]++;
        }

        
        for(int i=0;i<n1;i++){
            m[s2[i]]++;
        }

        if(check==m){return true;}

        int start=n1;
        while(start<n2){
            m[s2[start]]++;
            m[s2[start-n1]]--;
            if(check==m){return true;}
            start++;
        }

        return false;

    }
};
