class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p=0,m=prices[0];
        int n=prices.size();
        for(int i=1;i<n;i++){
            if(m>prices[i]){
                m=prices[i];
            }
            else
            p=max(prices[i]-m,p);
        }
        return p;
    }
};