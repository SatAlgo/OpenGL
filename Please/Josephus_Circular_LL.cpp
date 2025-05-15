#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to create a circular linked list with n nodes
Node* createCircularLinkedList(int n) {
    Node* head = new Node();
    head->data = 1;
    Node* temp = head;

    // Create the linked list with n nodes
    for (int i = 2; i <= n; i++) {
        temp->next = new Node();
        temp = temp->next;
        temp->data = i;
    }
    temp->next = head; // Make the list circular
    return head;
}

// Function to solve the Josephus problem
int josephus(int n, int m) {
    Node* start = createCircularLinkedList(n);
    Node* ptr = start;
    Node* save = start;

    while (ptr->next != ptr) { // Loop until one node remains
        int count = 1;
        while (count != m) {   // Move (m-1) nodes forward
            save = ptr;
            ptr = ptr->next;
            count++;
        }

        // Remove the m-th node (ptr)
        save->next = ptr->next; // Skip over the m-th node
        delete ptr;             // Delete the m-th node
        ptr = save->next;       // Move to the next node
    }
    return ptr->data;  // Return the last remaining node's data
}

int main() {
    int n = 5; // Number of people
    int m = 3; // Step count

    int safePosition = josephus(n, m);
    cout << "The safe position is: " << safePosition << endl;

    return 0;
}
