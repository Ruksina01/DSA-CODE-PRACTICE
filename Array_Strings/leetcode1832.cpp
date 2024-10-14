//  Check if the Sentence Is Pangram | LeetCode 1832
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//  Check if the Sentence Is Pangram
bool checkIfPangram(string &str)
{
    vector<bool> ans(26, 0);
    for (int i = 0; i < str.length(); i++)
    {
        ans[str[i]-'a'] = 1;
    }
    for (int i = 0; i < 26; i++)
    {
        if(ans[i]==0) return 0;
    }
    return 1;
}

int main()
{
    string str = "thequickbrownfoxjumpsoverthelazydog";
    string str2 = "leetcode";
    cout << checkIfPangram(str) << endl;
    cout << checkIfPangram(str2) << endl;
    return 0;
}