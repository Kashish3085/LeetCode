class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int s=0;
        int c=0;
        m[0]=1;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            if(m.count(s-k)){
                c+=m[s-k];
            }
            m[s]++;
        }
        return c;
    }
};