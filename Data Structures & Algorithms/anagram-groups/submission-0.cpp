class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>m;
        vector<vector<string>>a;
        for(auto x:strs){
            string z=x;
            sort(z.begin(),z.end());
            m[z].push_back(x);
        }
        for(auto w:m){
            a.push_back(w.second);
        }
        return a;
    }
};