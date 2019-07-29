class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        if (n1 == 0)  return arr2;
        if (n2 == 0)  return arr1;
        vector<int> ret(max(n1, n2));
        int i = n1 - 1, j = n2 - 1, k = ret.size() - 1;
        while (i >= 0 && j >= 0 && k >= 0) {
            ret[k--] = arr1[i--] + arr2[j--];
        }
        while (i >= 0) {
            ret[k--] = arr1[i--];
        }
        while (j >= 0) {
            ret[k--] = arr2[j--];
        }
        k = ret.size() - 1;
        while (k >= 1) {
            //cout << ret[k] << endl;
            if (ret[k] >= 2) {
                ret[k] -= 2;
                ret[k-1] -= 1; 
            } else if (ret[k] < 0) {
                ret[k] += 2;
                ret[k-1] += 1;
            }
            k--;
        }
        if (ret[0] >= 2) {
            ret[0] -= 2;
            ret.insert(ret.begin(), 1);
            ret.insert(ret.begin(), 1);
        } else if (ret[0] < 0) {
            ret[0] += 2;
            ret.insert(ret.begin(), 1);
        }
        for (k = 0; k < ret.size(); ++k) {
            if (ret[k] != 0)  break;
        }
        vector<int> r;
        for (k; k < ret.size(); ++k) {
            r.push_back(ret[k]);
        }
        if (r.size() == 0)  r.push_back(0);
        return r;
    }
};