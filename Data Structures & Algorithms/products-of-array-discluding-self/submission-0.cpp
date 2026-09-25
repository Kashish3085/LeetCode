class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>t(n);
        int p=1,c=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0)
            p=p*nums[i];
            else
            c++;
        }
        for(int i=0;i<n;i++){
            if(c==0)
            t[i]=p/nums[i];
            else if(c==1){
                if(nums[i]==0){
                    t[i]=p;
                    break;
                } 
            }
            else
            break;
        }

        return t;
    }
};