//  Check if the Sentence Is Pangram | LeetCode 1832
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//  Check if the Sentence Is Pangram
string sort(string &str)
{
    vector<int> ans(26, 0);
    for (int i = 0; i < str.length(); i++)
    {
        ans[str[i]-'a']++;
    }
    string res;
    for (int i = 0; i < 26; i++)
    {
        char ch = 'a' + i;
        while(ans[i]){
            res+=ch;
            ans[i]--;
        }
    }
    return res;
}

int main()
{
    string str = "edcab";
    cout << sort(str) << endl;
    return 0;
}