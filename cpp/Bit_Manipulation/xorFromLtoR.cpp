#include <bits/stdc++.h>
using namespace std;

int findXOR(int n){

    if(n % 4 == 1) return 1;
    else if(n % 4 == 2) return n + 1;
    else if(n % 4 == 3) return 0;
    else return n;

    return 0;
}

int xorLtoR(int low, int high){
    // eg: low = 4 | high = 7
    // so we need ( 4 ^ 5 ^ 6 ^ 7)
    // what we can do is find xor(4-1) ^ xor(high)
    // gives = ( 1 ^ 2 ^ 3) ^ ( 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7) ==> ( 4 ^ 5 ^ 6 ^ 7)

    return findXOR(low - 1) ^ findXOR(high);
}

int main(){
    int n = 10;

    cout << "FUNCTION: XOR from range L to R \n";
    // navie approach is to traverse from L to R (1 to n)
    // TC: O(n)

    // Optimized approach ( finding pattern ) TC: O(1)
    // n = 1  xor = 1
    // n = 2  xor = 3
    // n = 3  xor = 0
    // n = 4  xor = 4
    
    // n = 5  xor = 1
    // n = 6  xor = 7
    // n = 7  xor = 0
    // n = 8  xor = 8

    // n % 4 == 1; ans = 1
    // n % 4 == 2; ans = n + 1
    // n % 4 == 3; ans = 0
    // n % 4 == 0; ans = n

    cout << "XOR of 1 to " << n << " " << findXOR(n) << "\n";
    cout << "XOR of Low to high = " << xorLtoR(4,7) << "\n";
    return 0;
}
