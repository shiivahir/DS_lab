//
//  main.cpp
//  practical_3
//
//  Created by apexpredator on 17/07/26.
//
/*Write a program to implement stack using array. Demonstrate the following operations on stack: push(), pop( ), peek( ) and display( )*/

#include <iostream>
#include<stack>
using namespace std;

int main() {
    stack<int> s;
    
    s.push(10);
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);
    s.push(16);
    s.push(17);
    s.push(18);
    
    stack<int> temp = s;

    while(!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop() ;
        cout<< endl;
    }
    cout<< "Top element: " << s.top()<< endl;
    
    cout<<"Poping the top element: " << endl;
    s.pop();
    cout<<"Top element after pop: " << s.top()<<endl;
    
    return 0;
}
