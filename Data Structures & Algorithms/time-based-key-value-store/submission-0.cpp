

class TimeMap {
public:
    map<string, vector<pair<int,string>> >m;//name, list<timestamp,msg>

    TimeMap() {
        
    }

    int binaryseach(vector<pair<int,string>> & listmsg,int timestamp){
        int ans=-1;
        int left=0,right=listmsg.size()-1;

        while(left<=right){
            int mid=(left+right)/2;
            if(listmsg[mid].first<=timestamp){
                ans=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return ans;

    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(m.find(key)==m.end()){ //key not gound
            return "";
        }
        vector<pair<int,string>> & listmsg= m[key];

        int ind= binaryseach(listmsg,timestamp);

        return ind==-1? "" : listmsg[ind].second;

    }
};
