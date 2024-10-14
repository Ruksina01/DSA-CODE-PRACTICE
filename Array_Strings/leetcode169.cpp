// Majority Element | Leetcode 169

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Optimized Code
int OptimizedMajorityElement(vector<int> &arr) // tc --> o(nlogn)
{
    int n = arr.size();
    // sort function
    sort(arr.begin(), arr.end());

    int freq = 1, ans = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            freq++;
        }
        else
        {
            freq = 1;
            ans = arr[i];
        }
        if (freq > n / 2)
        {
            return ans;
        }
    }
    return ans;
}

// Moore's Voting algoirthm
int MooreMajorityElement(vector<int> &arr) // tc --> o(n)
{
    int n = arr.size();

    int freq = 1, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (freq == 0)
        {
            ans = arr[i];
        }
        if (ans == arr[i]) // if
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }
    //
    int count = 0; // Only when the problem says majoritylekemt may exit or not
    for(int vals: arr){
        if(ans==vals){
            count++;
        }
    }
    if(count>n/2) return ans;
    else return -1;
    //
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 2, 1, 2};
    int omj = OptimizedMajorityElement(arr);
    cout << omj << " " << endl;
    int moore = MooreMajorityElement(arr);
    cout << moore << " " << endl;

    return 0;
}