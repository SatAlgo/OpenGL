#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


class HashTable {
private:
    int TABLE_SIZE = 11;
    vector<int> keys;
    vector<int> values;

public:
    
    HashTable() {
        keys.resize(TABLE_SIZE, -1);
        values.resize(TABLE_SIZE, -1);
    }

    
    int HashFunc(int key) {
        return key % TABLE_SIZE;
    }

    
    void Insert(int key, int value) {
        int hashIndex = HashFunc(key);
        int i = 0;

    
        while (keys[(hashIndex + i * i) % TABLE_SIZE] != -1) {
            i++;
            if (i >= TABLE_SIZE) {
                cout << "Hash table overflow! Unable to insert key: " << key << endl;
                return;
            }
        }

        
        int finalIndex = (hashIndex + i * i) % TABLE_SIZE;
        keys[finalIndex] = key;
        values[finalIndex] = value;
        cout << "Inserted key " << key << " for category " << value << " at index " << finalIndex << endl;
    }

    
    void Display() {
        cout << "\nHash Table Contents:\n";
        cout << setw(10) << "Index" << setw(20) << "Number of Mangoes" << setw(20) << "Category" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << setw(10) << i << setw(20) << (keys[i] == -1 ? "EMPTY" : to_string(keys[i]))
                 << setw(20) << (values[i] == -1 ? "EMPTY" : to_string(values[i])) << endl;
        }
    }
};


int main() {
    
    int categories[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int mangoes[] = {25, 15, 10, 5, 11, 19, 16, 36, 42, 28, 32};
    int n = sizeof(categories) / sizeof(categories[0]);

   
    HashTable hashTable;

    
    for (int i = 0; i < n; i++) {
        hashTable.Insert(mangoes[i], categories[i]);
    }

    
    hashTable.Display();

    return 0;
}

