//
//  main.cpp
//  practical_4B
//
//  Created by apexpredator on 14/08/26.
//

#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

int main()
{
    string exp, x;
    stack<double> s;

    cout << "Enter postfix: ";
    getline(cin, exp);

    stringstream ss(exp);

    while (ss >> x)
    {
        if (x != "+" && x != "-" && x != "*" && x != "/" && x != "^" && x != "$")
        {
            s.push(stod(x));
        }
        else
        {
            double b = s.top(); s.pop();
            double a = s.top(); s.pop();

            if (x == "+") s.push(a + b);
            if (x == "-") s.push(a - b);
            if (x == "*") s.push(a * b);
            if (x == "/") s.push(a / b);
        }
    }

    cout << "Result: " << s.top() << endl;

    return 0;
}
