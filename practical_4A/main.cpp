// Simple Infix to Postfix converter (2nd year friendly)
// Supports: single-letter/digit operands, + - * / operators, and parentheses ()
// Example: A+(B*C) -> ABC*+

#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Return precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Check if character is one of our operators
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Convert an infix expression (like A+B*C) to postfix (like ABC*+)
string infixToPostfix(const string &expr) {
    stack<char> st;      // stack for operators and parentheses
    string postfix;      // result string

    for (char c : expr) {
        // Ignore spaces
        if (isspace(static_cast<unsigned char>(c))) continue;

        // If operand (letter or digit), add directly to output
        if (isalnum(static_cast<unsigned char>(c))) {
            postfix += c;
        }
        // If '(', push to stack
        else if (c == '(') {
            st.push(c);
        }
        // If ')', pop until '('
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty() && st.top() == '(') {
                st.pop(); // remove '('
            } else {
                // Mismatched parentheses
                return "Error: mismatched parentheses";
            }
        }
        // If operator, pop higher/equal precedence operators first
        else if (isOperator(c)) {
            while (!st.empty() && isOperator(st.top()) && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
        else {
            // Unknown character
            return string("Error: invalid character '") + c + "'";
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        if (st.top() == '(') return "Error: mismatched parentheses";
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    cout << "Enter infix expression (use letters/digits and + - * / with parentheses):\n";
    string line;
    getline(cin, line);

    string result = infixToPostfix(line);
    cout << "Postfix: " << result << '\n';
    return 0;
}
