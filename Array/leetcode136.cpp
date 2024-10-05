//  Single Number | Leetcode 136
#include <iostream>
#include <vector>
using namespace std;
//  Single Number
//  T.C -> O(n)
int singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (int i : nums)
    {
        ans ^= i; // XOR
    }
    return ans;
}
int main()
{
    int ans = 0;
    vector<int> vec = {1, 2, 3, 1, 3, 2, 8};
    int x = singleNumber(vec);
    cout << x << endl;

    return 0;
}