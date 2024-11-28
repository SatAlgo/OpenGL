#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* next;

    Node(int k) : key(k), next(nullptr) {}
};

class HashTable {
private:
    int TABLE_SIZE;
    Node** table;

public:
    HashTable(int size) {
        TABLE_SIZE = size;
        table = new Node*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            Node* current = table[i];
            while (current) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    int HashFunc(int key) {
        return key % TABLE_SIZE;
    }

    void Insert(int key) {
        int hash_val = HashFunc(key);
        Node* newNode = new Node(key);
        newNode->next = table[hash_val];
        table[hash_val] = newNode;
        cout << "Inserted key " << key << " at index " << hash_val << endl;
    }

    void Remove(int key) {
        int hash_val = HashFunc(key);
        Node* current = table[hash_val];
        Node* prev = nullptr;
        while (current != nullptr && current->key != key) {
            prev = current;
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Key " << key << " not found in the hash table." << endl;
            return;
        }
        if (prev == nullptr) {
            table[hash_val] = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
        cout << "Key " << key << " removed from index " << hash_val << endl;
    }

    bool Search(int key) {
        int hash_val = HashFunc(key);
        Node* current = table[hash_val];
        while (current != nullptr) {
            if (current->key == key) {
                cout << "Key " << key << " found at index " << hash_val << endl;
                return true;
            }
            current = current->next;
        }
        cout << "Key " << key << " not found in the hash table." << endl;
        return false;
    }

    void Display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << ": ";
            Node* current = table[i];
            if (!current) {
                cout << "NULL";
            }
            while (current) {
                cout << current->key << " -> ";
                current = current->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    int data[] = {33, 56, 78, 12, 10, 67, 89, 99, 100, 23, 45, 71, 39, 62, 59, 90, 91, 20, 75, 66};
    int n = sizeof(data) / sizeof(data[0]);

    HashTable hash(10);

    for (int i = 0; i < n; i++) {
        hash.Insert(data[i]);
    }

    cout << "\nHash Table Contents:\n";
    hash.Display();

    int searchKey = 78;
    cout << "\nSearching for key " << searchKey << ":\n";
    hash.Search(searchKey);

    int removeKey = 45;
    cout << "\nRemoving key " << removeKey << ":\n";
    hash.Remove(removeKey);

    cout << "\nHash Table after removal:\n";
    hash.Display();

    return 0;
}
