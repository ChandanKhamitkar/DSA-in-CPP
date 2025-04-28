#include <bits/stdc++.h>
using namespace std;

string conver2Binary(int num)
{
    string ans = "";

    while (num != 1)
    {
        if (num % 2 == 1)
            ans += '1';
        else
            ans += '0';
        num /= 2;
    }
    if (num == 1)
        ans += '1';
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int num = 13;

    string res = conver2Binary(num);
    cout << "Binary of " << num << " " << res << "\n";
    return 0;
}
