#include <iostream>
using namespace std;

class node {
public:
    int prn;
    char name[50];
    char branch[30];
    float cgpa;
    node* next;
};

class circularLinkedList {
private:
    node* head;

public:
    circularLinkedList() {
        head = NULL;
    }

    // Function prototypes
    void make_list();
    void display_list();
    void insert_at_start();
    void insert_at_end();
    void insert_bet_pos();
    void insert_bet_val();
    void deletefirst();
    void deletelast();
    void deleteval();
    void deletepos();
    void search();
    void sort();
};

void circularLinkedList::make_list() {
    node* p;
    node* temp = NULL;
    int choice = 1;
    while (choice == 1) {
        if (head == NULL) {
            head = new node;
            cout << "Enter the PRN, Name, Branch, and CGPA for the first node:" << endl;
            cin >> head->prn >> head->name >> head->branch >> head->cgpa;
            head->next = head; // Circular connection
            p = head;
        } else {
            temp = new node;
            cout << "Enter PRN, Name, Branch, and CGPA for the next node:" << endl;
            cin >> temp->prn >> temp->name >> temp->branch >> temp->cgpa;
            temp->next = head; // New node points to head
            p->next = temp; // Previous node points to new node
            p = p->next;
        }
        cout << "Enter 1 to insert another node, or 0 to stop: ";
        cin >> choice;
    }
}

void circularLinkedList::display_list() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    node* p = head;
    do {
        cout << "PRN: " << p->prn << endl;
        cout << "Name: " << p->name << endl;
        cout << "Branch: " << p->branch << endl;
        cout << "CGPA: " << p->cgpa << endl;
        cout << " -> ";
        p = p->next;
    } while (p != head);
    cout << "Circular back to head." << endl;
}

void circularLinkedList::insert_at_start() {
    node* temp = new node;
    cout << "Enter the information:" << endl;
    cout << "Enter PRN: ";
    cin >> temp->prn;
    cout << "Enter Name: ";
    cin >> temp->name;
    cout << "Enter Branch: ";
    cin >> temp->branch;
    cout << "Enter CGPA: ";
    cin >> temp->cgpa;

    if (head == NULL) {
        head = temp;
        head->next = head;
    } else {
        node* p = head;
        while (p->next != head) {
            p = p->next;
        }
        temp->next = head;
        p->next = temp;
        head = temp; // New node becomes head
    }
}

void circularLinkedList::insert_at_end() {
    node* temp = new node;
    cout << "Enter the information:" << endl;
    cout << "Enter PRN: ";
    cin >> temp->prn;
    cout << "Enter Name: ";
    cin >> temp->name;
    cout << "Enter Branch: ";
    cin >> temp->branch;
    cout << "Enter CGPA: ";
    cin >> temp->cgpa;

    if (head == NULL) {
        head = temp;
        head->next = head;
    } else {
        node* p = head;
        while (p->next != head) {
            p = p->next;
        }
        temp->next = head;
        p->next = temp;
    }
}

void circularLinkedList::insert_bet_pos() {
    int pos;
    cout << "Enter the position to insert at:" << endl;
    cin >> pos;

    if (pos == 1) {
        insert_at_start();
        return;
    }

    node* temp = new node;
    node* p = head;
    
    for (int i = 1; i < pos - 1 && p->next != head; i++) {
        p = p->next;
    }

    temp->next = p->next;
    p->next = temp;

    cout << "Enter the information:" << endl;
    cout << "Enter PRN: ";
    cin >> temp->prn;
    cout << "Enter Name: ";
    cin >> temp->name;
    cout << "Enter Branch: ";
    cin >> temp->branch;
    cout << "Enter CGPA: ";
    cin >> temp->cgpa;
}

void circularLinkedList::insert_bet_val() {
    int p_val;
    cout << "Enter PRN to insert after:" << endl;
    cin >> p_val;

    node* p = head;
    do {
        if (p->prn == p_val) {
            node* temp = new node;
            cout << "Enter the information:" << endl;
            cout << "Enter PRN: ";
            cin >> temp->prn;
            cout << "Enter Name: ";
            cin >> temp->name;
            cout << "Enter Branch: ";
            cin >> temp->branch;
            cout << "Enter CGPA: ";
            cin >> temp->cgpa;

            temp->next = p->next;
            p->next = temp;
            return;
        }
        p = p->next;
    } while (p != head);

    cout << "PRN not found." << endl;
}

void circularLinkedList::deletefirst() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    if (head->next == head) { // Only one node
        delete head;
        head = NULL;
    } else {
        node* p = head;
        while (p->next != head) {
            p = p->next;
        }
        node* temp = head;
        head = head->next;
        p->next = head;
        delete temp;
    }
}

void circularLinkedList::deletelast() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    if (head->next == head) { // Only one node
        delete head;
        head = NULL;
    } else {
        node* p = head;
        node* prev = NULL;
        while (p->next != head) {
            prev = p;
            p = p->next;
        }
        prev->next = head;
        delete p;
    }
}

void circularLinkedList::deleteval() {
    int p_val;
    cout << "Enter the PRN:" << endl;
    cin >> p_val;

    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    node* p = head;
    node* prev = NULL;

    if (p->prn == p_val) {
        deletefirst();
        return;
    }

    do {
        prev = p;
        p = p->next;
    } while (p != head && p->prn != p_val);

    if (p == head) {
        cout << "PRN not found." << endl;
        return;
    }

    prev->next = p->next;
    delete p;
}

void circularLinkedList::deletepos() {
    int pos;
    cout << "Enter the position to delete:" << endl;
    cin >> pos;

    if (pos == 1) {
        deletefirst();
        return;
    }

    node* p = head;
    node* prev = NULL;

    for (int i = 1; i < pos && p->next != head; i++) {
        prev = p;
        p = p->next;
    }

    if (p == head) {
        cout << "Position out of range." << endl;
        return;
    }

    prev->next = p->next;
    delete p;
}

void circularLinkedList::search() {
    int prno;
    node* p = head;
    cout << "Enter the PRN no: ";
    cin >> prno;

    do {
        if (p->prn == prno) {
            cout << "Found in the list: " << endl;
            cout << "PRN: " << p->prn << endl;
            cout << "Name: " << p->name << endl;
            cout << "Branch: " << p->branch << endl;
            cout << "CGPA: " << p->cgpa << endl;
            return;
        }
        p = p->next;
    } while (p != head);

    cout << "PRN not found." << endl;
}

void circularLinkedList::sort() {
    if (head == NULL || head->next == head) {
        return;
    }

    node* p = head;
    node* temp;

    do {
        temp = p->next;
        while (temp != head) {
            if (p->prn > temp->prn) {
                // Swap the data
                swap(p->prn, temp->prn);
                swap(p->name, temp->name);
                swap(p->branch, temp->branch);
                swap(p->cgpa, temp->cgpa);
            }
            temp = temp->next;
        }
        p = p->next;
    } while (p->next != head);

    cout << "List sorted based on PRN numbers." << endl;
}

int main() {
    circularLinkedList obj;
    int choice;

    while (1) {
        cout << "1. Make List" << endl;
        cout << "2. Display List" << endl;
        cout << "3. Insert at Start" << endl;
        cout << "4. Insert at End" << endl;
        cout << "5. Insert at Position" << endl;
        cout << "6. Insert after a value" << endl;
        cout << "7. Delete first node" << endl;
        cout << "8. Delete last node" << endl;
        cout << "9. Delete node by value" << endl;
        cout << "10. Delete node by position" << endl;
        cout << "11. Search" << endl;
        cout << "12. Sort" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            obj.make_list();
            break;
        case 2:
            obj.display_list();
            break;
        case 3:
            obj.insert_at_start();
            break;
        case 4:
            obj.insert_at_end();
            break;
        case 5:
            obj.insert_bet_pos();
            break;
        case 6:
            obj.insert_bet_val();
            break;
        case 7:
            obj.deletefirst();
            break;
        case 8:
            obj.deletelast();
            break;
        case 9:
            obj.deleteval();
            break;
        case 10:
            obj.deletepos();
            break;
        case 11:
            obj.search();
            break;
        case 12:
            obj.sort();
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}
