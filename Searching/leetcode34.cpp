// Find First and Last Position of Element in Sorted Array | Leetcode 34
#include <iostream>
#include <vector>
using namespace std;

// Find First and Last Position of Element in Sorted Array
vector<int> Fisrt_Last(vector<int> &arr, int target)
{
    int n = arr.size();
    int start = 0, end = n - 1, first = -1, last = -1, mid;

    //  Left part of Array
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (target == arr[mid])
        {
            first = mid;
            end = mid - 1;
        }
        else if (target > arr[mid])
            start = mid + 1;
        else
        {
            end = mid - 1;
        }
    }
    // Resetting
    start = 0;
    start = 0;
    end = n - 1;
    //  Right part of Array
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (target == arr[mid])
        {
            last = mid;
            start = mid + 1;
        }
        else if (target > arr[mid])
            start = mid + 1;
        else
        {
            end = mid - 1;
        }
    }
    return {first, last};
}
int main()
{
    vector<int> arr = {1, 4, 8, 8, 9, 10};
    vector<int> result = Fisrt_Last(arr, 8);
    cout << "First Occurrence: " << result[0] << endl;
    cout << "Last Occurrence: " << result[1] << endl;

    return 0;
}