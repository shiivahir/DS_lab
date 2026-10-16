//
//  main.cpp
//  practical_10
//
//  Created by apexpredator on 16/10/26.
//

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "Enter a number between 1 and 100." << endl;
        return 1;
    }

    int arr[100], bubble[100], selection[100];

    cout << "Enter " << n << " elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        bubble[i] = arr[i];
        selection[i] = arr[i];
    }

    cout << "\nOriginal array: ";
    display(arr, n);

    bubbleSort(bubble, n);
    cout << "After Bubble Sort: ";
    display(bubble, n);

    selectionSort(selection, n);
    cout << "After Selection Sort: ";
    display(selection, n);

    return 0;
}
