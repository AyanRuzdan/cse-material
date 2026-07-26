## Code
```cpp
class Twitter {
private:
    map<int, vector<pair<int, int>>> twt;
    map<int, set<int>> flws;
    int time;

public:
    Twitter() { time = 0; }

    void postTweet(int userId, int tweetId) {
        twt[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (auto& t : twt[userId]) {
            pq.push(t);
            if (pq.size() > 10)
                pq.pop();
        }
        for (int followee : flws[userId]) {
            for (auto& t : twt[followee]) {
                pq.push(t);
                if (pq.size() > 10)
                    pq.pop();
            }
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

    void follow(int followerId, int followeeId) {
        flws[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        flws[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
```
