class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int radius = 0;
        sort(heaters.begin(), heaters.end());
        for (auto house : houses) {
            auto num = lower_bound(heaters.begin(), heaters.end(), house);
            auto dist = numeric_limits<int>::max();
            if (num != heaters.end()) dist = min(dist, *num - house);
            if (num != heaters.begin()) dist = min(dist, house - *(num - 1));
            radius = max(dist, radius);
        }
        return radius;
    }
};
