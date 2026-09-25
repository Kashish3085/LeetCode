class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int c = 0, count = 0, temp = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (c == 0 || nums[i] - temp == 1) {
                c++;}
            else if (nums[i]== temp)
                continue;
            else
                c = 1;
            count = max(count, c);
            temp = nums[i];
        }
        return count;
    }
};
