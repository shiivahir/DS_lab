//
//  main.cpp
//  practical_11
//
//  Created by apexpredator on 16/10/26.
//


#include <iostream>
using namespace std;

int main() {
    int n, key;
    int a[50];

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0 || n > 50) {
        cout << "Invalid number of elements." << endl;
        return 1;
    }

    cout << "Enter elements in random order: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Enter element to search: ";
    cin >> key;

    // Binary Search
    int low = 0;
    int high = n - 1;
    int found = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (a[mid] == key) {
            found = mid;
            break;
        } else if (a[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (found != -1) {
        cout << "Element found at position "
             << found + 1 << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}

