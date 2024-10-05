// Product of Array Except Self  | Leetcode 238
#include <iostream>
#include<vector>
using namespace std;

// Product of Array Except Self 
vector<int> sum(vector<int>& arr){ // Tc -> O(n)
    int n = arr.size();
    vector<int> ans(n,1);
    for (int i = 1; i < n; i++)
    {
        ans[i] = ans[i-1]* arr[i-1];
    }
    int suffix = 1;
    for (int i = n-2; i >= 0; i--)
    {
        suffix *= arr[i+1];
        ans[i] *= suffix;
    }

    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4};
    vector<int> res = sum(arr);
    for(int val: res){
        cout << val << " ";
    }
    return 0;
}