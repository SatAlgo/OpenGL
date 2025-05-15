#include <iostream>
using namespace std;

class node {
public:
    int prn;
    char name[50];
    char branch[30];
    float cgpa;
    node* next;
    node* prev; // New pointer to keep track of the previous node
};

class doublyLinkedList {
private:
    node* head;

public:
    doublyLinkedList() {
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
    void sort();
    void search();
};

void doublyLinkedList::make_list() {
    node* p;
    node* temp = NULL;
    int choice = 1;
    while (choice == 1) {
        if (head == NULL) {
            head = new node;
            cout << "Enter the PRN, Name, Branch, and CGPA for the first node:" << endl;
            cin >> head->prn >> head->name >> head->branch >> head->cgpa;
            head->next = head->prev = NULL;
            p = head;
        } else {
            temp = new node;
            cout << "Enter PRN, Name, Branch, and CGPA for the next node:" << endl;
            cin >> temp->prn >> temp->name >> temp->branch >> temp->cgpa;
            temp->next = NULL;
            temp->prev = p; // Set previous pointer to the last node
            p->next = temp;
            p = p->next;
        }
        cout << "Enter 1 to insert another node, or 0 to stop: ";
        cin >> choice;
    }
}

void doublyLinkedList::display_list() {
    node* p = head;
    while (p != NULL) {
        cout << "PRN: " << p->prn << endl;
        cout << "Name: " << p->name << endl;
        cout << "Branch: " << p->branch << endl;
        cout << "CGPA: " << p->cgpa << endl;
        cout << "<->"; // Displaying bi-directional link
        p = p->next;
    }
    cout << "NULL" << endl;
}

void doublyLinkedList::insert_at_start() {
    node* temp = new node;
    cout << "Enter the information:" << endl;
    cout << "Enter prn: ";
    cin >> temp->prn;
    cout << "Enter name: ";
    cin >> temp->name;
    cout << "Enter branch: ";
    cin >> temp->branch;
    cout << "Enter CGPA: ";
    cin >> temp->cgpa;
    temp->next = head;
    temp->prev = NULL;

    if (head != NULL) {
        head->prev = temp;
    }
    head = temp;
}

void doublyLinkedList::insert_at_end() {
    node* p = head;
    node* temp = new node;
    cout << "Enter the information:" << endl;
    cout << "Enter prn: ";
    cin >> temp->prn;
    cout << "Enter name: ";
    cin >> temp->name;
    cout << "Enter branch: ";
    cin >> temp->branch;
    cout << "Enter CGPA: ";
    cin >> temp->cgpa;
    temp->next = NULL;

    if (head == NULL) {
        temp->prev = NULL;
        head = temp;
    } else {
        while (p->next != NULL) {
            p = p->next;
        }
        temp->prev = p;
        p->next = temp;
    }
}

void doublyLinkedList::insert_bet_pos() {
    int pos;
    cout << "Enter the position to insert at:" << endl;
    cin >> pos;

    node* temp = new node;
    node* p = head;
    
    for (int i = 1; i < pos - 1 && p != NULL; i++) {
        p = p->next;
    }

    if (pos == 1) {
        insert_at_start();
        return;
    } else if (p != NULL) {
        temp->next = p->next;
        if (p->next != NULL) {
            p->next->prev = temp;
        }
        p->next = temp;
        temp->prev = p;
    } else {
        cout << "Position out of range" << endl;
        return;
    }

    cout << "Enter the information:" << endl;
    cout << "Enter prn: ";
    cin >> temp->prn;
    cout << "Enter name: ";
    cin >> temp->name;
    cout << "Enter branch: ";
    cin >> temp->branch;
    cout << "Enter CGPA: ";
    cin >> temp->cgpa;
}

void doublyLinkedList::insert_bet_val() {
    int p_val;
    cout << "Enter PRN to insert after:" << endl;
    cin >> p_val;

    node* p = head;
    while (p != NULL && p->prn != p_val) {
        p = p->next;
    }

    node* temp = new node;

    if (p != NULL) {
        temp->next = p->next;
        if (p->next != NULL) {
            p->next->prev = temp;
        }
        p->next = temp;
        temp->prev = p;
    } else {
        cout << "PRN not found" << endl;
        return;
    }

    cout << "Enter the information:" << endl;
    cout << "Enter prn: ";
    cin >> temp->prn;
    cout << "Enter name: ";
    cin >> temp->name;
    cout << "Enter branch: ";
    cin >> temp->branch;
    cout << "Enter CGPA: ";
    cin >> temp->cgpa;
}

void doublyLinkedList::deletefirst() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    node* p = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    delete p;
}

void doublyLinkedList::deletelast() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }

    p->prev->next = NULL;
    delete p;
}

void doublyLinkedList::deleteval() {
    int p_val;
    cout << "Enter the PRN:" << endl;
    cin >> p_val;

    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    node* p = head;
    while (p != NULL && p->prn != p_val) {
        p = p->next;
    }

    if (p == NULL) {
        cout << "PRN not found" << endl;
        return;
    }

    if (p->prev != NULL) {
        p->prev->next = p->next;
    } else {
        head = p->next;
    }

    if (p->next != NULL) {
        p->next->prev = p->prev;
    }

    delete p;
}

void doublyLinkedList::deletepos() {
    int pos;
    cout << "Enter the position to delete:" << endl;
    cin >> pos;

    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    node* p = head;

    for (int i = 1; i < pos && p != NULL; i++) {
        p = p->next;
    }

    if (p == NULL) {
        cout << "Position out of range" << endl;
        return;
    }

    if (p->prev != NULL) {
        p->prev->next = p->next;
    } else {
        head = p->next;
    }

    if (p->next != NULL) {
        p->next->prev = p->prev;
    }

    delete p;
}

void doublyLinkedList::search() {
    int prno;
    node* p = head;
    cout << "Enter the PRN no: ";
    cin >> prno;

    while (p != NULL) {
        if (p->prn == prno) {
            cout << "Found in the list: " << endl;
            cout << "PRN: " << p->prn << endl;
            cout << "Name: " << p->name << endl;
            cout << "Branch: " << p->branch << endl;
            cout << "CGPA: " << p->cgpa << endl;

            char update_choice;
            cout << "Do you want to update this record? (y/n): ";
            cin >> update_choice;

            if (update_choice == 'y' || update_choice == 'Y') {
                cout << "Enter new details:" << endl;
                cout << "Enter PRN: ";
                cin >> p->prn;
                cout << "Enter Name: ";
                cin >> p->name;
                cout << "Enter Branch: ";
                cin >> p->branch;
                cout << "Enter CGPA: ";
                cin >> p->cgpa;
            }
            return;
        }
        p = p->next;
    }

    cout << "PRN not found." << endl;
}

void doublyLinkedList::sort() {
    if (head == NULL) {
        return;
    }

    node* p = head;
    node* temp;

    while (p != NULL) {
        temp = p->next;
        while (temp != NULL) {
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
    }

    cout << "List sorted based on PRN numbers." << endl;
}

int main() {
    doublyLinkedList obj;
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
