class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size() || s.empty() || t.empty())
            return "";
        int n = t.size();
        int m = s.size();
        vector<int> f(128, 0);
        vector<int> w(128, 0);
        for (int i = 0; i < n; i++) {
            char c1 = t[i];
            f[c1]++;
        }
        int l = 0;
        int minlen = m + 1;
        int c = 0;
        int st = 0;
        for (int r = 0; r < m; r++) {
            char c2 = s[r];
            w[c2]++;
            if (w[c2] <= f[c2])
                c++;
            while (c == n) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    st = l;
                }
                char left = s[l];
                if (w[left] == f[left])
                    c--;
                w[left]--;
                l++;
            }
        }
        if (minlen == m + 1)
            return "";
        return s.substr(st, minlen);
    }
};