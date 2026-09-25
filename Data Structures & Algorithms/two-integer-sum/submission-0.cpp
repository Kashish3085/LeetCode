class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> diff;
        for(int i=0;i<nums.size();i++){
            if(diff.count(nums[i])){
                return {diff[nums[i]],i};
            }
            else{
                diff[target-nums[i]]=i;
            }
        }
        return {};
    }
};