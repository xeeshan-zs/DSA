#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (arr[i]>arr[j]) {
                swap(arr[i],arr[j]);

            }
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 45, 67, 89};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    int arr1[n], arr2[n], arr3[n];
    copy(arr, arr + n, arr1);
    copy(arr, arr + n, arr2);
    copy(arr, arr + n, arr3);

    bubbleSort(arr1, n);
    cout << "Sorted array with bubble sort: \t";
    printArray(arr1, n);

    selectionSort(arr2, n);
    cout << "Sorted array with selection sort: ";
    printArray(arr2, n);

    insertionSort(arr3, n);
    cout << "Sorted array with insertion sort: ";
    printArray(arr3, n);

    return 0;
}