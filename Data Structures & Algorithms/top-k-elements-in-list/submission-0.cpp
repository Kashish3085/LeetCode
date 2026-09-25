class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        priority_queue<pair<int,int>>pq;
        vector<int>o(k);

        for(auto& x:nums){
            m[x]++;
        }
        for(auto& pair:m){
            pq.push(make_pair(pair.second,pair.first));
        }
        for(auto& a:o){
            a=pq.top().second;
            pq.pop();
        }
        return(o);
    }
};