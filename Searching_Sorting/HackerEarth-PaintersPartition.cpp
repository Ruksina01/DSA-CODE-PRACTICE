//  Painter's Partition Problem | Hacker Earth
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//  Painter's Partition Problem

// T.C -> O(n)
bool isValid(vector<int> &boards, int n, int m, int maxAllowedblocks)
{
    int painter = 1, time = 0;
    for (int i = 0; i < n; i++)
    {
        if(boards[i]>maxAllowedblocks) return false;
        if (time + boards[i] <= maxAllowedblocks)
        {
            time += boards[i];
        }
        else
        {
            painter++;
            time = boards[i];
        }
    }
    return painter > m ? false : true;
}
// T.C -> O(longN * n)
int paintersTime(vector<int> &boards, int n, int m)
{
    if (m > n)
        return -1;
    int ans = -1;
    int sum = 0;
    int maxValue = INT_MIN;
    for (int i = 0; i < n; i++) // O(n)
    {
        sum += boards[i];
        maxValue = max(maxValue,boards[i]);
    }
    int start = maxValue;
    int end = sum;
    while (start <= end)
    { // O(longN)
        int mid = start + (end - start) / 2;
        if (isValid(boards, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {40,30,10,20};
    int n = arr.size();
    int m = 2;
    cout << paintersTime(arr, n, m);

    return 0;
}