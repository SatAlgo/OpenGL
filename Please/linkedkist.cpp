#include <iostream>
using namespace std;

class node{
public:
    int prn;
    char name[50];
    char branch[30];
    float cgpa;
    node* next;
};

class linkedlist{
private:
    node* head;
    int pos;

public:
    linkedlist() : head(NULL){}

    void make_list();
    void display_list();
    void insert();
    void insert_at_start();
    void insert_at_last();
    void insert_bet_pos();
    void insert_bet_val();
    void delete_list();
    void del_head();
    void del_end();
    void del_val();
    void del_pos();
    void search();
    void update();
    void sort();
};

void linkedlist::make_list(){
    node* p = nullptr;
    int choice = 1;
    
    while (choice == 1){
        node* temp = new node;
        cout<<"Enter PRN: ";
        cin>>temp->prn;
        cout<<"Enter Name: ";
        cin>>temp->name;
        cout<<"Enter Branch: ";
        cin>>temp->branch;
        cout<<"Enter CGPA: ";
        cin>>temp->cgpa;
        temp->next = nullptr;

        if (head == NULL){
            head = temp;
            p = head;
        }else{
            p->next = temp;
            p = p->next;
        }

        cout<<"Enter 1 to continue or 0 to stop: ";
        cin>>choice;
    }
}

void linkedlist::display_list(){
    node* p = head;
    
    while (p != NULL){
        cout<<p->prn<<" "<<p->name<<" "<<p->branch<<" "<<p->cgpa<<" -> ";
        p = p->next;
    }
    cout<<"NULL"<<endl;
}

void linkedlist::insert(){
    int choice;
    cout<<"Enter 1 to insert at start\n";
    cout<<"Enter 2 to insert at last\n";
    cout<<"Enter 3 to insert by position\n";
    cout<<"Enter 4 to insert by value\n";
    cin>>choice;

    switch (choice){
        case 1: insert_at_start(); break;
        case 2: insert_at_last(); break;
        case 3: insert_bet_pos(); break;
        case 4: insert_bet_val(); break;
        default: cout<<"Invalid choice entered\n";
    }
}

void linkedlist::insert_at_start(){
    node* temp = new node;
    cout<<"Enter PRN: ";
    cin>>temp->prn;
    cout<<"Enter Name: ";
    cin>>temp->name;
    cout<<"Enter Branch: ";
    cin>>temp->branch;
    cout<<"Enter CGPA: ";
    cin>>temp->cgpa;
    
    temp->next = head;
    head = temp;
}

void linkedlist::insert_at_last(){
    node* temp = new node;
    cout<<"Enter PRN: ";
    cin>>temp->prn;
    cout<<"Enter Name: ";
    cin>>temp->name;
    cout<<"Enter Branch: ";
    cin>>temp->branch;
    cout<<"Enter CGPA: ";
    cin>>temp->cgpa;
    temp->next = nullptr;

    if (head == NULL){
        head = temp;
    } else{
        node* p = head;
        while (p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
}

void linkedlist::insert_bet_pos(){
    int pos;
    cout<<"Enter the position to insert at: ";
    cin>>pos;

    if (pos == 1){
        insert_at_start();
        return;
    }

    node* p = head;
    node* temp = new node;
    cout<<"Enter PRN: ";
    cin>>temp->prn;
    cout<<"Enter Name: ";
    cin>>temp->name;
    cout<<"Enter Branch: ";
    cin>>temp->branch;
    cout<<"Enter CGPA: ";
    cin>>temp->cgpa;

    for (int i = 1; i < pos - 1; i++){
        p = p->next;
        if (p == NULL){
            cout<<"Position out of range\n";
            return;
        }
    }

    temp->next = p->next;
    p->next = temp;
}

void linkedlist::insert_bet_val(){
    int p_val;
    cout<<"Enter PRN to insert after: ";
    cin>>p_val;

    node* p = head;
    node* temp = new node;
    cout<<"Enter PRN: ";
    cin>>temp->prn;
    cout<<"Enter Name: ";
    cin>>temp->name;
    cout<<"Enter Branch: ";
    cin>>temp->branch;
    cout<<"Enter CGPA: ";
    cin>>temp->cgpa;

    while (p != NULL && p->prn != p_val){
        p = p->next;
    }

    if (p != NULL){
        temp->next = p->next;
        p->next = temp;
    } else{
        cout<<"PRN not found\n";
    }
}

void linkedlist::delete_list(){
    int choice;
    cout<<"Enter 1 to delete at start\n";
    cout<<"Enter 2 to delete at last\n";
    cout<<"Enter 3 to delete by position\n";
    cout<<"Enter 4 to delete by value\n";
    cin>>choice;

    switch (choice){
        case 1: del_head(); break;
        case 2: del_end(); break;
        case 3: del_pos(); break;
        case 4: del_val(); break;
        default: cout<<"Invalid choice\n";
    }
}

void linkedlist::del_head(){
    if (head == NULL) return;
    node* temp = head;
    head = head->next;
    delete temp;
}

void linkedlist::del_end(){
    if (head == NULL) return;

    node* p = head;
    node* q = NULL;

    while (p->next != NULL){
        q = p;
        p = p->next;
    }

    if (q != NULL){
        q->next = NULL;
    } else{
        head = NULL;
    }

    delete p;
}

void linkedlist::del_pos(){
    int pos;
    cout<<"Enter the position to delete: ";
    cin>>pos;

    if (pos == 1){
        del_head();
        return;
    }

    node* p = head;
    node* q = NULL;

    for (int i = 1; i < pos; i++){
        q = p;
        p = p->next;
        if (p == NULL){
            cout<<"Position out of range\n";
            return;
        }
    }

    q->next = p->next;
    delete p;
}

void linkedlist::del_val(){
    int val;
    cout<<"Enter the PRN to delete: ";
    cin>>val;

    node* p = head;
    node* q = NULL;

    while (p != NULL){
        if (p->prn == val){
            if (q == NULL){
                head = p->next;
            } else{
                q->next = p->next;
            }
            delete p;
            return;
        }
        q = p;
        p = p->next;
    }

    cout<<"PRN not found\n";
}

void linkedlist::search(){
    int no1;
    cout<<"Enter PRN to search: ";
    cin>>no1;

    node* p = head;
    while (p != NULL){
        if (p->prn == no1){
            cout<<"Details found\n";
            return;
        }
        p = p->next;
    }

    cout<<"PRN not found\n";
}

void linkedlist::update(){
    int no1;
    cout<<"Enter PRN to update: ";
    cin>>no1;

    node* p = head;
    while (p != NULL){
        if (p->prn == no1){
            cout<<"Enter new Name: ";
            cin>>p->name;
            cout<<"Enter new Branch: ";
            cin>>p->branch;
            cout<<"Enter new CGPA: ";
            cin>>p->cgpa;
            return;
        }
        p = p->next;
    }

    cout<<"PRN not found\n";
}

void linkedlist::sort(){
    if (head == NULL) return;

    for (node* p = head; p != NULL; p = p->next){
        for (node* q = p->next; q != NULL; q = q->next){
            if (p->prn > q->prn){
                swap(p->prn, q->prn);
                swap(p->name, q->name);
                swap(p->branch, q->branch);
                swap(p->cgpa, q->cgpa);
            }
        }
    }

    display_list();
}

int main(){
    linkedlist l1;
    int choice, ch;

    do{
        cout<<"1. Create List\n2. Display List\n3. Insert\n4. Delete\n5. Search\n6. Update\n7. Sort\n";
        cin>>ch;

        switch (ch){
            case 1: l1.make_list(); break;
            case 2: l1.display_list(); break;
            case 3: l1.insert(); break;
            case 4: l1.delete_list(); break;
            case 5: l1.search(); break;
            case 6: l1.update(); break;
            case 7: l1.sort(); break;
            default: cout<<"Invalid choice\n";
        }

        cout<<"Enter 1 to continue, 0 to exit: ";
        cin>>choice;

    } while (choice != 0);

    return 0;
}
