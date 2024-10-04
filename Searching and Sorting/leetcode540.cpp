// Single Element in a Sorted Array | Leetcode 540
#include <iostream>
#include <vector>
using namespace std;

// Single Element in a Sorted Array
int singleNonDuplicate(vector<int>& arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];
        
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        // Check for edge cases (first or last element)
        if (mid == 0 && arr[mid] != arr[mid + 1])
            return arr[mid];
        if (mid == n - 1 && arr[mid] != arr[mid - 1])
            return arr[mid];

        // Check if mid is the single element
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
            return arr[mid];

        // Even index logic
        if (mid % 2 == 0)
        {
            if (arr[mid] == arr[mid + 1])
                start = mid + 2;
            else
                end = mid - 1;
        }
        // Odd index logic
        else
        {
            if (arr[mid] == arr[mid - 1])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    return -1;  // Default return -1;
}

int main()
{
    vector<int> arr = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << singleNonDuplicate(arr) << endl;

    return 0;
}
