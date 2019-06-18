class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int nhouse = houses.size();
        int nheater = heaters.size();
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        if (nhouse == 0)  return 0;
        int curHeaterIndex = 0;
        int minRadius = 0;
        for (int i = 0; i < nhouse; ++i) {
            for (; curHeaterIndex < nheater; ++curHeaterIndex) {
                if (curHeaterIndex == 0 && heaters[curHeaterIndex] > houses[i])
                    break;
                if (curHeaterIndex == nheater - 1) 
                    break;
                if (heaters[curHeaterIndex] <= houses[i] && heaters[curHeaterIndex+1] > houses[i])
                    break;
            }
            if (curHeaterIndex == nheater - 1) {
                minRadius = max(minRadius, abs(heaters[curHeaterIndex] - houses[i]));
            } else {
                minRadius = max(minRadius, min(abs(heaters[curHeaterIndex] - houses[i]), abs(heaters[curHeaterIndex+1] - houses[i])));
            }
            //cout << curHeaterIndex << " " << minRadius << endl;
        }
        return minRadius;
    }
};