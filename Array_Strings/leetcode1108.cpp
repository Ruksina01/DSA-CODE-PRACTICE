//  Defanging an IP Address | LeetCode 1108
#include <iostream>
#include <string>
using namespace std;

//  Defanging an IP Address
string defangIPaddr(string& address) {
    string ans;
    int i = 0;
    while(i < address.length()){
        if(address[i] == '.')
        ans+="'[.]";
        else{
            ans+=address[i];
        }
        i++;
    }
    return ans;
}

int main()
{
    string str = "1.1.1.1";
    cout << defangIPaddr(str); 
    return 0;
}