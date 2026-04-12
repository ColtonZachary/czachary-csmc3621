#include <iostream>
#include "HashTable.h"
using namespace std;

int main() {

    HashTable ht1;

    ht1.insert(52);
    ht1.insert(20);
    ht1.insert(48);
    ht1.insert(36);
    ht1.insert(10);
    ht1.insert(92);
    ht1.insert(28);
    ht1.insert(72);

    cout << endl;
    cout << "// Hash Table ht1 (table size: 10)" << endl << endl;
    ht1.print_hash_table();
    cout << endl;
    cout << "Search 45 in ht1: " << ht1.search(45) << endl;
    cout << "Search 92 in ht1: " << ht1.search(92) << endl;

    cout << endl << endl;

    HashTable ht2(7);

    ht2.insert(52);
    ht2.insert(20);
    ht2.insert(48);
    ht2.insert(36);
    ht2.insert(10);
    ht2.insert(92);
    ht2.insert(28);
    ht2.insert(72);

    cout << "// Hash Table ht2 (table size: 7)" << endl << endl;
    ht2.print_hash_table();
    cout << endl;
    cout << "Search 12 in ht2: " << ht2.search(12) << endl;
    cout << "Search 50 in ht2: " << ht2.search(50) << endl;

    cout << endl << endl;

    HashTable ht3(13);

    ht3.insert(52);
    ht3.insert(20);
    ht3.insert(48);
    ht3.insert(36);
    ht3.insert(10);
    ht3.insert(92);
    ht3.insert(28);
    ht3.insert(72);

    cout << "// Hash Table ht3 (table size: 13)" << endl << endl;
    ht3.print_hash_table();
    cout << endl;
    cout << "Search 36 in ht3: " << ht3.search(36) << endl;
    cout << "Search 52 in ht3: " << ht3.search(52) << endl;

    cout << endl << endl;

    HashTable ht4(3);

    ht4.insert(0);
    ht4.insert(1);
    ht4.insert(11);
    ht4.insert(101);
    ht4.insert(2);
    ht4.insert(12);
    ht4.insert(102);
    ht4.insert(3);
    ht4.insert(13);
    ht4.insert(103);
    ht4.insert(4);

    ht4.remove(0);
    ht4.remove(4);

    cout << "// Hash Table ht4 (table size: 3)" << endl << endl;
    ht4.print_hash_table();
    cout << endl;
    cout << "Search 101 in ht4: " << ht4.search(101) << endl;
    cout << "Search 0 in ht4: " << ht4.search(0) << " (REMOVED)" << endl;

    cout << endl << endl;
}