//  String Rotated by 2 Places | GeeksForGeeks
#include <iostream>
#include <string>
using namespace std;

void isRotatedClockwise(string &str)
{
    if (str.length() < 2)
        return;
    char last = str[str.length() - 1];
    char secondLast = str[str.length() - 2];
    int index = str.length() - 3;
    while (index >= 0)
    {
        str[index + 2] = str[index];
        index--;
    }
    str[0] = secondLast;
    str[1] = last;
}
void isRotatedAntiClockwise(string &str)
{
    if (str.length() < 2)
        return;
    char first = str[0];
    char second = str[1];
    int index = 2;
    while (index < str.length())
    {
        str[index - 2] = str[index];
        index++;
    }
    str[str.length() - 2] = first;
    str[str.length() - 1] = second;
}
//  String Rotated by 2 Places
bool isRotated(string str1, string str2)
{
    if (str1.length() != str2.length())
        return 0;
    string clockwise = str1;
    string anticlokwise = str1;
    isRotatedAntiClockwise(anticlokwise);
    isRotatedClockwise(clockwise);

    return (anticlokwise == str2 || clockwise == str2);
}

int main()
{
    string str1 = "amazon";
    string str2 = "azonam";
    cout << isRotated(str1, str2);
    return 0;
}