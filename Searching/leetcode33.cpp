// Search in Rotated Sorted Array | Leetcode 33
#include <iostream>
#include <vector>
using namespace std;

// Search in Rotated Sorted Array
int search(vector<int> &arr, int target)
{
    int n = arr.size();
    int start = 0, end = n - 1, mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (target == arr[mid])
        {
            return mid;
        }
        //  Left part Sorted
        else if (arr[start] <= arr[mid])
        {
            if (arr[start] <= target && target <= arr[mid])
            {
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        //  Right part Sorted
        else
        {
            if (arr[mid] <= target && target <= arr[end])
            {
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    cout << search(arr, 0);

    return 0;
}