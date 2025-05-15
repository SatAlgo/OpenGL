#include <iostream>
using namespace std;

class node {
public:
    int prn;
    char name[50];
    char branch[30];
    float cgpa;
    node* next;
    node* prev;
};

class doublyCircularLinkedList {
private:
    node* head;

public:
    doublyCircularLinkedList() {
        head = NULL;
    }

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

void doublyCircularLinkedList::make_list() {
    node* p;
    node* temp = NULL;
    int choice = 1;

    while (choice == 1) {
        if (head == NULL) {
            head = new node;
            cout << "Enter PRN, Name, Branch, and CGPA for the first node:" << endl;
            cin >> head->prn >> head->name >> head->branch >> head->cgpa;
            head->next = head;
            head->prev = head;
            p = head;
        } else {
            temp = new node;
            cout << "Enter PRN, Name, Branch, and CGPA for the next node:" << endl;
            cin >> temp->prn >> temp->name >> temp->branch >> temp->cgpa;
            temp->next = head;
            temp->prev = p;
            p->next = temp;
            head->prev = temp;
            p = temp;
        }
        cout << "Enter 1 to insert another node, or 0 to stop: ";
        cin >> choice;
    }
}

void doublyCircularLinkedList::display_list() {
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
        cout << "<->"; // Displaying bi-directional link
        p = p->next;
    } while (p != head);
    cout << "HEAD" << endl;
}

void doublyCircularLinkedList::insert_at_start() {
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
        temp->next = temp;
        temp->prev = temp;
        head = temp;
    } else {
        node* last = head->prev;
        temp->next = head;
        temp->prev = last;
        last->next = temp;
        head->prev = temp;
        head = temp;
    }
}

void doublyCircularLinkedList::insert_at_end() {
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
        temp->next = temp;
        temp->prev = temp;
        head = temp;
    } else {
        node* last = head->prev;
        temp->next = head;
        temp->prev = last;
        last->next = temp;
        head->prev = temp;
    }
}

void doublyCircularLinkedList::insert_bet_pos() {
    int pos;
    cout << "Enter the position to insert at: ";
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

    if (p->next == head && pos != 1) {
        cout << "Position out of range" << endl;
        return;
    }

    temp->next = p->next;
    temp->prev = p;
    p->next->prev = temp;
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

void doublyCircularLinkedList::insert_bet_val() {
    int p_val;
    cout << "Enter PRN to insert after: ";
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
            temp->prev = p;
            p->next->prev = temp;
            p->next = temp;
            return;
        }
        p = p->next;
    } while (p != head);

    cout << "PRN not found." << endl;
}

void doublyCircularLinkedList::deletefirst() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    node* last = head->prev;
    node* temp = head;
    head = head->next;
    head->prev = last;
    last->next = head;

    delete temp;
}

void doublyCircularLinkedList::deletelast() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    node* last = head->prev;
    last->prev->next = head;
    head->prev = last->prev;

    delete last;
}

void doublyCircularLinkedList::deleteval() {
    int p_val;
    cout << "Enter PRN: ";
    cin >> p_val;

    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    node* p = head;
    do {
        if (p->prn == p_val) {
            if (p == head && head->next == head) {
                delete head;
                head = NULL;
                return;
            }

            if (p == head) {
                deletefirst();
                return;
            }

            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
            return;
        }
        p = p->next;
    } while (p != head);

    cout << "PRN not found." << endl;
}

void doublyCircularLinkedList::deletepos() {
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;

    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    if (pos == 1) {
        deletefirst();
        return;
    }

    node* p = head;
    for (int i = 1; i < pos && p->next != head; i++) {
        p = p->next;
    }

    if (p == head) {
        cout << "Position out of range" << endl;
        return;
    }

    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
}

void doublyCircularLinkedList::search() {
    int prno;
    cout << "Enter PRN no: ";
    cin >> prno;

    node* p = head;
    do {
        if (p->prn == prno) {
            cout << "Found in the list:" << endl;
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

void doublyCircularLinkedList::sort() {
    if (head == NULL) {
        return;
    }

    node* p = head;
    node* temp;

    do {
        temp = p->next;
        while (temp != head) {
            if (p->prn > temp->prn) {
                swap(p->prn, temp->prn);
                swap(p->name, temp->name);
                swap(p->branch, temp->branch);
                swap(p->cgpa, temp->cgpa);
            }
            temp = temp->next;
        }
        p = p->next;
    } while (p != head);
}

int main() {
    doublyCircularLinkedList list;
    list.make_list();
    list.display_list();
    list.insert_at_start();
    list.display_list();
    list.insert_at_end();
    list.display_list();
    list.insert_bet_pos();
    list.display_list();
    list.deletefirst();
    list.display_list();
    list.deletelast();
    list.display_list();
    list.search();
    list.sort();
    list.display_list();

    return 0;
}
