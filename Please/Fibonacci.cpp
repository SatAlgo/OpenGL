#include <iostream>
using namespace std;

int fibonacciSearch(int arr[], int n, int target) {
    // Initialize the Fibonacci numbers
    int fib2 = 0;         // (m-2)'th Fibonacci number
    int fib1 = 1;         // (m-1)'th Fibonacci number
    int fib = fib2 + fib1; // m'th Fibonacci number

    // Find the smallest Fibonacci number greater than or equal to n
    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    // Marks the range of the array being searched
    int offset = -1;

    // While there are elements to inspect
    while (fib > 1) {
        // Check the valid indseex
        int i = min(offset + fib2, n - 1);

        // If target is greater than the value at index i, search the right subarray
        if (arr[i] < target) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        // If target is less than the value at index i, search the left subarray
        else if (arr[i] > target) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        // Element found
        else
            return i;
    }

    // Check the last element
    if (fib1 && arr[offset + 1] == target)
        return offset + 1;

    // Element not found
    return -1;
}

int main() {
    int arr[] = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    cin>>target;

    int index = fibonacciSearch(arr, n, target);

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
