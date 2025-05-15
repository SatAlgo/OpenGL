#include <iostream>
#include <algorithm> // Include this header for std::swap
using namespace std;

int main() {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Unsorted array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Bubble Sort Logic
    for (int pass = size - 1; pass > 0; pass--) {
        bool swapped = false; // Reset swapped to false before each pass

        // Perform a single pass through the array
        for (int i = 0; i < pass; i++) {
            if (array[i] > array[i + 1]) { // Compare adjacent elements
                // Use std::swap to swap elements
                swap(array[i], array[i + 1]);
                swapped = true; // Mark that a swap occurred
            }
        }

        if (!swapped) {
            // If no swaps occurred in the current pass, the array is sorted
            break;
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
