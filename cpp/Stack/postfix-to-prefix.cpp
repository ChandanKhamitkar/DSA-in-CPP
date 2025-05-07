#include <bits/stdc++.h>
#include <map>
using namespace std;

string output = "";

string postfixToPrefix(string postfix)
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
            string newEle = ch + t2 + t1;
            st.push(newEle);
        }

    }
    
    return st.top();
}

int main()
{
    string postfix = "ab-de+f*/";
    string prefix = postfixToPrefix(postfix);
    cout << "postfix: " << postfix << " to prefix : " << prefix << "\n";
    return 0;
}