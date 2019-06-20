class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ret(2);
        if (area == 0)  return ret;
        int w = sqrt(area);
        while (true) {
            int l = area / w;
            if (l * w == area) {
                ret[1] = w;
                ret[0] = l;
                return ret;
            }
            w--;
        }
        return ret;
    }
};