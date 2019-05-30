class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        if (n == 0)  return 0;
        unordered_map<int, int> my_map;
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int sum = A[i] + B[j];
                if (my_map.count(sum) == 0)  my_map[sum] = 1;
                else  my_map[sum]++;
            }
        }
        //unordered_set<int> my_set;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int sum = C[i] + D[j];
                //if (my_set.count(sum) > 0)  continue;
                if (my_map.count(-sum) != 0)  {
                    //cout << sum << endl;
                    ret += my_map[-sum];
                }
                //my_set.insert(sum);
            }
        }
        return ret;
    }
};