//  Allocate Minimum Number of Pages from N books to M students | GeeksForGeeks
#include <iostream>
#include <vector>
using namespace std;

//  Book Allocation or Allocate Problem

// T.C -> O(n)
bool isValid(vector<int> &arr, int n, int m, int maxAllowedPages)
{
    int student = 1, pages = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxAllowedPages)
            return false;
        if (pages + arr[i] <= maxAllowedPages)
        {
            pages += arr[i];
        }
        else
        {
            student++;
            pages = arr[i];
        }
    }
    return student > m ? false : true;
}
// T.C -> O(longN * n)
int bookAllocated(vector<int> &arr, int n, int m)
{
    if (m > n)
        return -1;
    int ans = -1;
    int sum = 0;
    for (int i = 0; i < n; i++) // O(n)
    {
        sum += arr[i];
    }
    int start = 0;
    int end = sum;
    while (start <= end)
    { // O(longN)
        int mid = start + (end - start) / 2;
        if (isValid(arr, n, m, mid))
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
    vector<int> array = {12, 34, 67, 90};
    int n = 4;
    int m = 2;
    cout << bookAllocated(array, n, m);

    return 0;
}