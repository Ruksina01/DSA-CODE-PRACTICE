//  Maximum Subarray Sum | Leetcode 53
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Maximum Subarray Sum
int subArray(vector<int> &arr)
{ // TC -> O(n)
    int n = arr.size();
    int current_sum = arr[0];
    int max_sum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        current_sum+=arr[i];
        max_sum = max(current_sum, max_sum);
        if(current_sum < 0){
            current_sum=0;
        }
    }
