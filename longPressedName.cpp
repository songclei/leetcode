class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n1 = name.size();
        int n2 = typed.size();
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            int cnt = 1;
            while (i < n1 - 1 && name[i+1] == name[i])  {
                cnt++;
                i++;
            }
            while (j < n2 && typed[j] == name[i]) {
                cnt--;
                j++;
            }
            if (cnt > 0)  return false;
            i++;
        }
        if (i < n1 || j < n2)  return false;
        else return true;
    }
};