// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    string str = "chandan";
    // cout << "Enter name :";
    // cin >> name;

    // string output = "";
    // for(char x: name){
    //     output += x;
    //     cout << output << "\n";
    // }

    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        printf("%*c%*c\n", i, str[i - 1], len * 2 - i * 2, str[i - 1]);
    }
    printf("%*c\n", len, str[len - 1]);
    for (int i = len - 1; i >= 1; i--)
    {
        printf("%*c%*c\n", i, str[i - 1], len * 2 - i * 2, str[i - 1]);
    }

    return 0;
}