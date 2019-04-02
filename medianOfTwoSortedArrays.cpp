class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m == 0) {
            if (n % 2 == 0)
                return (nums2[n/2-1] + nums2[n/2]) / 2.0;
            else 
                return nums2[n/2];
        }
        if (n == 0) {
            if (m % 2 == 0)
                return (nums1[m/2-1] + nums1[m/2]) / 2.0;
            else 
                return nums1[m/2];
        }
        int mid = (m + n) / 2;
        int i = 0;
        int j = 0;
        int count = 0;
        float ret;
        if ((m + n) % 2 == 0) {
            bool find_flag1 = false;
            bool find_flag2 = false;
            int n1, n2;
            while ((!find_flag1 || !find_flag2) && i < m && j < n) {
                while ((!find_flag1 || !find_flag2) && i < m && nums1[i] <= nums2[j]) {
                    if (count == mid - 1) {
                        n1 = nums1[i];
                        find_flag1 = true;
                    }
                    if (count == mid) {
                        n2 = nums1[i];
                        find_flag2 = true;
                    }
                    i++;
                    count++;
                }
                if ((!find_flag1 || !find_flag2) && i == m) {
                    if (!find_flag1) {
                        n1 = nums2[mid-m-1];
                        find_flag1 = true;
                    }
                    n2 = nums2[mid-m];
                    find_flag2 =true;
                }
                while ((!find_flag1 || !find_flag2) && j < n && nums2[j] <= nums1[i]) {
                    if (count == mid - 1) {
                        n1 = nums2[j];
                        find_flag1 = true;
                    }
                    if (count == mid) {
                        n2 = nums2[j];
                        find_flag2 = true;
                    }
                    j++;
                    count++;
                }
                if ((!find_flag1 || !find_flag2) && j == n) {
                    if (!find_flag1) {
                        n1 = nums1[mid-n-1];
                        find_flag1 = true;
                    }
                    n2 = nums1[mid-n];
                    find_flag2 =true;
                }
            }
            cout << n1 << " " << n2 << endl;
            ret = (n1 + n2) / 2.0;
        } else {
            bool find_flag = false;
            while (!find_flag && i < m && j < n) {
                while (!find_flag && i < m && nums1[i] <= nums2[j]) {
                    if (count == mid)  {
                        ret = nums1[i];
                        find_flag = true;
                    }
                    i++;
                    count++;
                }
                if (!find_flag && i == m)  {
                    ret = nums2[mid-m];
                    find_flag = true;
                }
                while (!find_flag && j < n && nums2[j] <= nums1[i]) {
                    if (count == mid)  {
                        ret = nums2[j];
                        find_flag = true;
                    }
                    j++;
                    count++;
                }
                if (!find_flag && j == n)  {
                    ret = nums1[mid-n];
                    find_flag = true;
                }
            }
        }
        return ret;
    }
};
