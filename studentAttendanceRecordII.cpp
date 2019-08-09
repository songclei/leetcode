class Solution {
public:
// 有限状态机:
// type0: 无A且最后0个L
// type1: 无A且最后1个L
// type2: 无A且最后2个L
// type3: 有A且最后0个L
// type4: 有A且最后1个L
// type5: 有A且最后2个L
    int checkRecord(int n) {
        vector<long long> type(6);
        if (n == 0)  return 0;
        type[0] = type[1] = type[3] = 1;
        for (int i = 2; i <= n; ++i) {
            vector<long long> tmp(6);
            tmp[0] = type[0] + type[1] + type[2];
            tmp[1] = type[0];
            tmp[2] = type[1];
            tmp[3] = type[0] + type[1] + type[2] + type[3] + type[4] + type[5];
            tmp[4] = type[3];
            tmp[5] = type[4];
            for (int j = 0; j < 6; ++j) {
                type[j] = tmp[j] % 1000000007; 
            }
        }
        long cnt = 0;
        for (int i = 0; i < 6; ++i) {
            cnt += type[i];
        }
        return cnt % 1000000007;
    }
};