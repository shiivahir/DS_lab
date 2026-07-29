//
//  main.cpp
//  practical 1
//
//  Created by apexpredator on 16/07/26.
//Write a program to create an array and demonstrate insertion, deletion, traversal, and search operations.


#include<iostream>
 using namespace std;
 
 int main()
 {
 int a;
 int arr[10] = {10 ,11 ,12 ,13 ,14 ,15 ,16 ,17};
 int n =8;
 int pos ;
 int value ;
 bool found = false;
 
 cout<< "\nCurrent array  ";
 for (int i=0; i<n; i++)
 { cout<< arr[i]<<" ";}
 
 cout<< "\nEnter no on which you want to add element " ;
 cin>> pos;
 
 
 if (pos < 0 || pos > n)
 {
 cout << "Invalid Position!\n";
 return 0;
 }
 
 
 cout<< "\nEnter value to insert ";
 cin>> value;
 
 
 
 for (int i = n; i > pos; i--) {
 arr[i] = arr[i - 1];
 }
 arr[pos] = value;
 n++;
 
 cout << "\nArray after insertion: ";
 for (int i=0 ; i<n; i++)
 {cout<<arr[i]<<" ";}
     
     
     cout<< "\nEnter no on which you want to delete element " ;
     cin>> pos;
     
     
     if (pos < 0 || pos > n)
         {
             cout << "Invalid Position!\n";
             return 0;
         }
     
     for (int i = pos; i < n - 1; i++)
     {
         arr[i] = arr[i + 1];
     }
     n--;
    
     cout << "\nArray after deletion: ";
     for (int i=0 ; i<n; i++)
     {cout<<arr[i]<<" ";}
 
     cout << "\n\nEnter element to search: ";
         cin >> a;

         for (int i = 0; i < n; i++)
         {
             if (arr[i] == a)
             {
                 cout << a << " found at index " << i << endl;
                 found = true;
                 break;
             }
         }

         if (!found)
         {
             cout << a << " not found in the array." << endl;
         }

     return 0;
 }
 
