#include <bits/stdc++.h>
using namespace std;

#define MM 8  

class node {
public:
    int orderno;
    node *next;

    node(int x) {
        orderno = x;
        next = NULL;
    }
};

class CLL {
private:
    int count;
    node *head;

public:
    CLL() {
        head = NULL;
        count = 0;
    }

    void addOrder(int x);
    void serveOrder();
    void display();
};

void CLL::addOrder(int x) {
    node *temp = new node(x);

    if (head == NULL) {
        head = temp;
        temp->next = head;
    } else {
        node *last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = temp;
        temp->next = head;
    }
    count++;
}

void CLL::serveOrder() {
    if (head == NULL) {
        cout << "No orders to serve." << endl;
        return;
    }

    node *temp = head;
    if (head->next == head) {
        head = NULL;
    } else {
        node *last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = head->next;
        head = head->next;
    }
    delete temp;
    count--;
}

void CLL::display() {
    if (head == NULL) {
        cout << "No orders to display." << endl;
        return;
    }

    node *temp = head;
    do {
        cout << "Order ID: " << temp->orderno << endl;
        temp = temp->next;
    } while (temp != head);
}

int main() {
    CLL orders;
    int choice, orderId;

    do {
        
        cout << "\nMenu:\n";
        cout << "1. Add Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                
                cout << "Enter order ID to add: ";
                cin >> orderId;
                orders.addOrder(orderId);
                cout << "Order " << orderId << " added successfully.\n";
                break;
            case 2:
                
                orders.serveOrder();
                cout << "First order served.\n";
                break;
            case 3:
                
                cout << "Displaying all orders:\n";
                orders.display();
                break;
            case 4:
                
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 4);

    return 0;
}


