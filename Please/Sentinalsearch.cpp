#include <iostream>
using namespace std;

int sentinelSearch(int arr[], int n, int target) {
    // Save the last element of the array
    int last = arr[n - 1];

    // Place the target as the "sentinel" at the end of the array
    arr[n - 1] = target;

    int i = 0;

    // Loop until we find the target
    while (arr[i] != target) {
        i++;
    }

    // Restore the last element of the array
    arr[n - 1] = last;

    // Check if the target is found within the valid range of the array
    if (i < n - 1 || arr[n - 1] == target)
        return i;

    // If not found, return -1
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 40;

    int index = sentinelSearch(arr, n, target);

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
bubble