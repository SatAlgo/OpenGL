#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int orderNo;
    Node *next;
};

class Pizza
{
    Node *head;

public:
    int create();
    void display();
    void insertFirst();
    void insertLast();
    void deleteFirst();
    void deleteLast();

    Pizza() { head = NULL; }
};

int Pizza::create()
{
    int ch, n = 0;
    do
    {
        Node *temp = new Node();
        cout << "Enter orderNo: ";
        cin >> temp->orderNo;

        if (head == NULL)
        {
            head = temp;
            temp->next = head;
        }
        else
        {
            Node *p = head;
            while (p->next != head)
                p = p->next;
            p->next = temp;
            temp->next = head;
        }
        n++;
        cout << "Do you want to continue? (1/0): ";
        cin >> ch;

    } while (ch == 1);

    return n;
}

void Pizza::display()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node *temp = head;
    do
    {
        cout << temp->orderNo << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

void Pizza::insertFirst()
{

    int orderNo;
    cout << "Enter OrderNo: " << endl;
    cin >> orderNo;

    if (head == NULL)
    {
        cout << "You cannot insert" << endl;
        return;
    }
    else
    {
        Node *temp = new Node(), *p = head;
        temp->orderNo = orderNo;

        while (p->next != head)
            p = p->next;

        temp->next = head;
        p->next = temp;
        head = temp;
    }
}

void Pizza::insertLast()
{
    int orderNo;
    cout << "Enter OrderNo: " << endl;
    cin >> orderNo;

    if (head == NULL)
    {
        cout << "You cannot insert" << endl;
        return;
    }
    else
    {
        Node *temp = new Node(), *p = head;
        temp->orderNo = orderNo;

        while (p->next != head)
            p = p->next;

        p->next = temp;
        temp->next = head;
    }
}

void Pizza ::deleteFirst()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node *temp = head, *p = head;

    while (p->next != head)
    {
        p = p->next;
    }

    temp = head;
    head = head->next;
    p->next = head;
    delete temp;
    cout << "First node deleted" << endl;
}

void Pizza ::deleteLast()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node *temp = head, *p = head;

    while (p->next != head && p->next->next != head)
    {
        p = p->next;
    }

    temp = p->next;
    p->next = head;
    delete temp;
    cout << "Last node deleted" << endl;
}

int main()
{
    Pizza s;
    cout << "Create new list" << endl;
    int n = s.create();

    cout << "Number of nodes: " << n << endl;
    cout << "Displaying the list: " << endl;
    s.display();

    cout << "Inserting node at the beginning" << endl;
    s.insertFirst();

    cout << "Displaying the updated list: " << endl;
    s.display();

    cout << "Inserting node at the end" << endl;
    s.insertLast();

    cout << "Displaying the updated list: " << endl;
    s.display();

    cout << "Deleting the first node" << endl;
    s.deleteFirst();

    cout << "Displaying the updated list: " << endl;
    s.display();

    cout << "Deleting the last node" << endl;
    s.deleteLast();

    cout << "Displaying the updated list: " << endl;
    s.display();

    return 0;
}
