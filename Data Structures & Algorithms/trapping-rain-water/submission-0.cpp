class Solution {
public:
    int trap(vector<int>& height) {
        int lmax = 0, rmax = 0, t = 0;
        int n = height.size();
        int l = 0;
        int r = n - 1;
        while (l < r) {
            if(height[l]<height[r]){
                if(lmax>height[l]){
                    t=t+(lmax-height[l]);
                }
                else{
                    lmax=height[l];
                }
                l=l+1;
            }
            else{
                if(rmax>height[r]){
                    t=t+(rmax-height[r]);
                }
                else{
                    rmax=height[r];
                }
                r=r-1;
            }
        }
        return t;
    }
};