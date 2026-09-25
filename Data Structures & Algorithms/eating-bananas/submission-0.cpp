class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while (l <= r) {
            long long hours = 0;
            int k = l + (r - l) / 2;
            for (int i = 0; i < piles.size(); i++) {
                hours += ((long long)piles[i] + k - 1) / k;
            }
            if (hours <= h) {
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        return l;
    }
};
