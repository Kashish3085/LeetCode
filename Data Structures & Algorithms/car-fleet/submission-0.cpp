class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=speed.size();
        vector<pair<int,int>> cars;
        for(int i=0;i<n;i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(),cars.rend());
        double p=0;
        int f=0;
        for(int i=0;i<n;i++){
            double t=(double)(target-cars[i].first)/cars[i].second;
            if(t>p){
                f++;
                p=t;
            }
        }
        return f;
    }
};