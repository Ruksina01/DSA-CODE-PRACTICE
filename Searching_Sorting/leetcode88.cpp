//   Merge Sorted Array | Leetcode 88
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//   Merge Sorted Array
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int index = m + n - 1;
    int i = m - 1;
    int j = n - 1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[index] = nums1[i];
            i--;
        }
        else
        {
            nums1[index] = nums2[j];
            j--;
        }
        index--;
    }
    while (j >= 0)
    {
        nums1[index] = nums2[j];
        index--;
        j--;
    }
    while (i >= 0)
    {
        nums1[index] = nums1[i];
        index--;
        i--;
    }
}
int main()
{
    string str1 = "is2 sentence4 This1 a3";
    vector<int> nums1 = {1, 2, 3, 0, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 4, 5, 6};
    int n = 4;
    merge(nums1, m, nums2, n);
    for (int i : nums1)
    {
        cout << i << " ";
    }

    return 0;
}