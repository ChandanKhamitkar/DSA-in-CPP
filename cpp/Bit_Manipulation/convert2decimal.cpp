#include <bits/stdc++.h>
using namespace std;

int conver2Decimal(string num)
{
    int ans = 0, p2 = 1, n = num.length();

    for(int i = n-1; i>=0; i--){
        if(num[i] == '1'){
            ans += p2;
        }
        p2 *= 2;
    }
    return ans;
}

int main()
{
    string num = "11";

    int res = conver2Decimal(num);
    cout << "Decimal of " << num << " " << res << "\n";
    return 0;
}
