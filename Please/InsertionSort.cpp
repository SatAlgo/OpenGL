#include <iostream>
using namespace std;

int main() {
    int array[] = {64, 25, 12, 22, 11};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Unsorted array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Insertion Sort Logic
    for (int i = 1; i < size; i++) {
        int key = array[i]; // The element to be inserted
        int j = i - 1;

        // Move elements of the sorted portion that are greater than the key
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }

        // Insert the key into its correct position
        array[j + 1] = key;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
