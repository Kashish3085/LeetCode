class Solution {
   public:
    int characterReplacement(string s, int k) {
        vector<int> m(26, 0);
        int l = 0, mf = 0, ans = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s.at(i);
            m[c - 'A']++;
            mf = max(mf, m[c - 'A']);
            while (i - l + 1 - mf > k) {
                m[s.at(l) - 'A']--;
                l++;
            }
            ans = max(i - l + 1, ans);
        }
        return ans;
    }
};
