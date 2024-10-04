// Peak Index in Mountain Array | Leetcode 852
#include <iostream>
#include <vector>
using namespace std;

// Peak Index in Mountain Array
int peakIndexInMountainArray(vector<int> &arr)
{
    int n = arr.size();
    int start = 0, end = n - 1, mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid - 1] < arr[mid]) // peak is at right
            start = mid + 1;
        else // peak is at left
            end = mid - 1;
    }
    return -1;
}

int main()
{
    vector<int> arr = {0, 2, 1, 0};
    cout << peakIndexInMountainArray(arr);

    return 0;
}