//  Maximum Product Subarray | Leetcode 152
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Maximum Product Subarray

int maxProduct(vector<int> &arr)
{
    int n = arr.size();
    int current_sum = 1;
    int max_sum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        current_sum *= arr[i];
        max_sum = max(current_sum, max_sum);
        if (current_sum == 0)
        {
            current_sum = 1;
        }
    }
    // Reset Current;
    current_sum = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        current_sum *= arr[i];
        max_sum = max(current_sum, max_sum);
        if (current_sum == 0)
        {
            current_sum = 1;
        }
    }

    return max_sum;
}

int main()
{
    vector<int> arr = {2, 3, -2, 4};
    cout << maxProduct(arr);
    return 0;
}