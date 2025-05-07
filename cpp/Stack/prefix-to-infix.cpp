#include <bits/stdc++.h>
#include <map>
using namespace std;

string output = "";

string prefixToInfix(string prefix)
{
    stack<string> st;
    reverse(prefix.begin(), prefix.end());

    for (auto ch : prefix)
    {
        if (isalnum(ch))
        {
            string operand(1, ch);
            st.push(operand);
        }
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string newEle = '(' + t1 + ch + t2 + ')';
            st.push(newEle);
        }

    }
    
    return st.top();
}

int main()
{
    string prefix = "*+pq-mn";
    string infix = prefixToInfix(prefix);
    cout << "prefix: " << prefix << " to infix : " << infix << "\n";
    return 0;
}