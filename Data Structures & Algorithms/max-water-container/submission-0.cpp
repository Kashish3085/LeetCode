class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int max_c=0;
        while(l<r){
            int d=r-l;
            int h=min(height[l],height[r]);
            max_c=max(max_c,h*d);
            if(height[l]<=height[r]){
                l++;
                while(l<r && height[l]<height[l-1]){
                    l++;
                }
            }
            else if(height[l]>height[r]){
                r--;
                while(l<r && height[r]<height[r+1]){
                    r--;
                }
            }
        }
        return max_c;
        
    }
};