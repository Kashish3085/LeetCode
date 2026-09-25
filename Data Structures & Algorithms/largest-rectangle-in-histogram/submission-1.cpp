class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            int c;
            if (i == n) {
                c = 0;
            } else {
                c = heights[i];
            }
            while (!st.empty() && c < heights[st.top()]) {
                int x = st.top();
                st.pop();
                int l;
                if (st.empty()) {
                    l = -1;
                } else {
                    l = st.top();
                }
                int w = i - l - 1;
                int a = heights[x] * w;
                ans = max(ans, a);
            }
            if (i < n) {
                st.push(i);
            }
        }
        return ans;
    }
};