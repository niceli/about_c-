//https://leetcode-cn.com/problems/design-twitter/
//map(int, set<int>) -> follow
//map(int, Node*) -> user ->post_list
//prirority_queue -> mod when get posts
struct Node{
    int id;
    int time;
    Node(int id, int time): id(id),time(time) {}
    Node* next = NULL;
};

struct Cm {
    bool operator() (const Node* a, const Node* b) const {
        return a->time < b->time;
    }
};

class Twitter {
public:
    unordered_map<int, Node*> f;
    unordered_map<int, unordered_set<int>> mf;
    int time;
    /** Initialize your data structure here. */
    Twitter() {
        f.clear();
        mf.clear();
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        Node* n = new Node(tweetId, time++);
        if(f.find(userId) != f.end()) {
            n->next = f[userId];
        } 
        f[userId] = n;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        unordered_set<int> s;
        if(mf.find(userId) != mf.end()) s = mf[userId];
        s.insert(userId);
        priority_queue<Node*, vector<Node*>, Cm> q;
        for(auto i: s)  {
            if(f[i]) q.push(f[i]);
        }

        int count = 10;
        vector<int> ans;
        while(count > 0 && !q.empty()) {
            Node* n = q.top(); q.pop();
            if(n->next) q.push(n->next);
            ans.push_back(n->id);
            count--;
        }
        return ans;    
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        mf[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        mf[followerId].erase(followeeId);
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
