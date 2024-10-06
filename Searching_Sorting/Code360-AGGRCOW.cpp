//  AGGRCOW - Aggressive cows | Coding Ninja
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//  AGGRCOW - Aggressive cows

// T.C -> O(n)
bool isValid(vector<int> &stalls, int k, int mid)
{
    int n = stalls.size();
    int cows = 1;
    int cow_pos = stalls[0];
    for (int i = 0; i < n; i++)
    {
        if (stalls[i] - cow_pos >= mid)
        {
            cows++;
            cow_pos = stalls[i];
        }
        if (cows == k)
            return true;
    }
    return false;
}
// T.C -> O(logn)
int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());

    int ans = -1;
    int start = 0;
    int end = stalls[n - 1] - stalls[0];
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isValid(stalls, k, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> array = {4, 2, 1, 3, 6};
    int n = array.size();
    int k = 2;
    cout << aggressiveCows(array, k);

    return 0;
}