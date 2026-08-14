// Simple Infix to Postfix converter (2nd year friendly)
// Supports: single-letter/digit operands, + - * / operators, and parentheses ()
// Example: A+(B*C) -> ABC*+

#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int priority(char c)
{
    if (c == '^' || c == '$') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main()
{
    string infix, postfix = "";
    stack<char> a;

    cout << "Enter infix: ";
    cin >> infix;

    for (char c : infix)
    {
        if (isalnum(c))
            postfix += c;

        else if (c == '(')
            a.push(c);

        else if (c == ')')
        {
            while (a.top() != '(')
            {
                postfix += a.top();
                a.pop();
            }
            a.pop();
        }

        else
        {
            while (!a.empty() && a.top() != '(' &&
                   priority(a.top()) >= priority(c))
            {
                postfix += a.top();
                a.pop();
            }
            a.push(c);
        }
    }

    while (!a.empty())
    {
        postfix += a.top();
        a.pop();
    }

    cout << "Postfix: " << postfix << endl;

    return 0;
}
