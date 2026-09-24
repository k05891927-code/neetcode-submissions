class Twitter {
public:
    map<int,set<int>>follows;
    map<int,vector<pair<int,int>> >post;
    int time;
    Twitter() {
        time =0;
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        post[userId].push_back({time,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<> >pq;
        for(auto it:post[userId]){
            pq.push(it);
            if(pq.size()>10){
                pq.pop();
            }
        }
        for(auto followee: follows[userId]){
            for(auto feed: post[followee] ){
                pq.push(feed);
                if(pq.size()>10){
                    pq.pop();
                }
            }
        }

        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
