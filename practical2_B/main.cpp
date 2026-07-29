//
//  main.cpp
//  practical2_B
//
//  Created by apexpredator on 16/07/26.
//Demonstrate the concept of Call by value and Call by Reference.

#include <iostream>
using namespace std;



    void callbyvalue(int x)
    {
        x= x+10;
        cout<< "Value inside called by value function:  "<< x << endl;
        
    }
    
    void callbyreference( int &x)
    {
    x= x+10;
        cout<< "Value inside called by Reference function:  "<< x << endl;
    
    }


int main() {
    int x;
    cout<<"The expression is x= x+10"<< endl;
    cout<< "Enter the value of X: ";
    cin>> x;
    cout<< "Original Value is "<< x<< endl;
    
    callbyvalue(x);
       cout << "Value after Call by Value: " << x << endl;
    callbyreference(x);
    cout << "Value after Call by Reference: " << x << endl;


    
    return 0;
}
