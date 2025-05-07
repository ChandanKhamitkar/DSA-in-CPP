#include <bits/stdc++.h>
#include <map>
using namespace std;

// reverse the infix string
// infix to postfix
/// reverse the postfix

string infixToPrefix(string infix)
{
    stack<char> st;
    map<char, int> myMap = {
        {'^', 3},
        {'*', 2},
        {'/', 2},
        {'+', 1},
        {'-', 1}};
    string output = "";

    reverse(infix.begin(), infix.end());

    for (auto ch : infix)
    {
        if (isalnum(ch))
            output += ch;
        else if (ch == '(')
            st.push(ch);
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                output += st.top();
                st.pop();
            }
            if (!st.empty() && st.top() == '(')
                st.pop();
        }
        else if (myMap.find(ch) != myMap.end())
        {
            while (!st.empty() && st.top() != '(' &&
                   (myMap[st.top()] > myMap[ch] ||
                    (myMap[st.top()] == myMap[ch] && ch != '^')))
            {
                output += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty())
    {
        output += st.top();
        st.pop();
    }

    reverse(output.begin(), output.end());
    return output;
}

int main()
{
    string infix = "a+b*(c^d-e)";
    string prefix = infixToPrefix(infix);
    cout << "Infix: " << infix << " to prefix : " << prefix << "\n";
    return 0;
}