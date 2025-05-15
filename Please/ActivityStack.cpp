#include <bits/stdc++.h>
using namespace std;

// Helper function to remove the middle element of the stack
void deleteMiddleHelper(stack<int>& st, int current, int mid) {
    // Base case: If we've reached the middle, pop the element and return
    if (current == mid) {
        st.pop();
        return;
    }

    // Pop the top element and call the function recursively to reach the middle
    int topElement = st.top();
    st.pop();
    deleteMiddleHelper(st, current + 1, mid);

    // Push the elements back except the middle element
    st.push(topElement);
}

// Function to delete the middle element of the stack
void deleteMiddle(stack<int>& st) {
    if (st.empty()) return;

    int mid = st.size() / 2;  // Find the middle index
    deleteMiddleHelper(st, 0, mid); // Start recursive deletion
}

// Utility function to print the stack
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;

    // Push elements onto the stack
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << "Original Stack: ";
    printStack(st);

    // Push the elements again for demonstration
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    // Delete the middle element
    deleteMiddle(st);

    cout << "Stack after deleting middle element: ";
    printStack(st);

    return 0;
}
