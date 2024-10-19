//  Longest Substring Without Repeating Characters  || Leetcode 3
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//  Longest Substring Without Repeating Characters
//  Time Complexity - O(N) and Space Complexity = O(1)
int lengthOfLongestSubstring(string s)
{
    vector<bool> count(256, 0);
    int first = 0;
    int second = 0;
    int len = 0;
    while (second < s.length())
    {
        while (count[s[second]])
        {
            count[s[first]] = 0;
            first++;
        }
        count[s[second]] = 1;
        len = max(len, second - first + 1);
        second++;
    }
    return len;
}
int main(){
    string str = "abcabcbb";
    cout << lengthOfLongestSubstring(str) << endl;

}