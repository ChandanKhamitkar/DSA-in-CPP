#include <bits/stdc++.h>
#include <map>
using namespace std;

string output = "";

string postfixToInfix(string postfix)
{
    stack<string> st;

    for (auto ch : postfix)
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
            string newEle = '(' + t2 + ch + t1 + ')';
            st.push(newEle);
        }

    }
    
    return st.top();
}

int main()
{
    string postfix = "abcd^e-*+";
    string infix = postfixToInfix(postfix);
    cout << "postfix: " << postfix << " to infix : " << infix << "\n";
    return 0;
}