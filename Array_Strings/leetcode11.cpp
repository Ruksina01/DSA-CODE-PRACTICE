//  Container With Most Water   |   LeetCode 11

#include <iostream>
#include <vector>
using namespace std;

// BruteForce Method tc --> o(n^2)
int maxArea(vector<int> &height)
{
    int n = height.size();
    int maxwater = 0;
    int left, right;
    for (int left = 0; left < n; left++)
    {
        for (int right = left + 1; right < n; right++)
        {
            int w = right - left;
            int h = min(height[right], height[left]);
            int area = w * h;
            maxwater = max(maxwater, area);
        }
    }
    return maxwater;
}

//  Container With Most Water
// Optimzed method 2 pointer tc --> o(n)
int maxAreaWater(vector<int> &height)
{
    int n = height.size();
    int maxwater = 0;
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (height[i] < height[j])
        {
            i++;
        }
        else
        {
            j--;
        }
        int w = j - i;
        int h = min(height[i], height[j]);
        int area = w * h;
        maxwater = max(maxwater, area);
    }
    return maxwater;
}
int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int mj = maxAreaWater(height);
    cout << mj << " " << endl;

    return 0;
}