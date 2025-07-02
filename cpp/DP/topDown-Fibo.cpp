#include <bits/stdc++.h>
#include <map>
using namespace std;

int fibo(int n)
{
    if (n <= 1)
        return n;
    return fibo(n - 1) + fibo(n - 2);
}

int main()
{
    cout << fibo(9 - 1);
    return 0;
}
