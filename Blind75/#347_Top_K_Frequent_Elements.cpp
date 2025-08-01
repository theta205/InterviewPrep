class Solution {
public:
    using pii = pair<int, int>;  

    struct CompareBySecond {
        bool operator()(const pii& a, const pii& b) const {
            return a.second < b.second;  
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> m;
        priority_queue<pii, vector<pii>, CompareBySecond> pq;
        for (int num : nums) m[num]++;
        for (auto p : m) pq.push(p);
        while (k > 0) {ans.push_back(pq.top().first); pq.pop(); k--;}
        return ans;
    }
};

