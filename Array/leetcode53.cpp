//  Maximum Subarray Sum | Leetcode 53
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Maximum Subarray Sum
// TC -> O(n)
int maxSubArray(vector<int> &arr)
{
    int n = arr.size();
    int current_sum = 0;
    int max_sum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        current_sum += arr[i];
        max_sum = max(current_sum, max_sum);
        if (current_sum < 0)
        {
            current_sum = 0;
        }
    }
    return max_sum;
}

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(arr);
    return 0;
}