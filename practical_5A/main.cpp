//
//  main.cpp
//  practical_5A
//
//  Created by apexpredator on 30/07/26.
//

#include <iostream>
using namespace std;

int q[10], front = 0, rear = -1;

void enqueue(int x)
{
    if (rear == 4)
        cout << "Queue Full\n";
    else
        q[++rear] = x;
}

void dequeue()
{
    if (front > rear)
        cout << "Queue Empty\n";
    else
        cout << "Deleted: " << q[front++] << endl <<"\n";
}

void display()
{
    if (front > rear)
        cout << "Queue Empty\n";
    else
        for (int i = front; i <= rear; i++)
            cout << q[i] << " "<<"\n";
}

int main()
{
    int ch, x;
    do
    {
        cout << "Choose what to perform";
        cout << "\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n";
        cin >> ch;
        if (ch == 1)
        {
            cin >> x;
            enqueue(x);
        }
        else if (ch == 2)
            dequeue();
        else if (ch == 3)
            display();
    } while (ch != 4);
    return 0;
}
