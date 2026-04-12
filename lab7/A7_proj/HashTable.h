#pragma once
#ifndef HashTable_H
#define HashTable_H

#include <deque>
#include <iostream>
#include <string>

using namespace std;

class HashTable {
private:
  deque<int> *table; // instead of allocating a fix size like table[size], this
                     // is allocating the structure in the heap
  int size;
  int hash_function(
      int data) { // simple modulo function, index = key MOD tableSize
    return data % size;
  }

public:
  HashTable() { // default constructor
    this->size = 10;
    table = new deque<int>[this->size]; // array of deque<int>
  }

  HashTable(int size) { // customized size
    this->size = size;
    table = new deque<int>[this->size];
  }

  ~HashTable() { delete[] table; }

  void insert(int data) {
    /**
     * Inserts the data into the correct index. For insertion, we want O(1)
     * time, so we will insert in the front of the deque.
     *
     * This function will simply do the followings:
     * 1. hash the data key to get the appropriate index in the hash table
     * 2. insert the data key into the appropriate index
     *    (for inserting the data in the beginning of the STL deque, we use the
     * .push_front() method in the deque, the push_front() method will accept
     * the data we want to insert)
     *
     * @param data, int, the data we want to insert in the hash table
     *
     */
    int index = hash_function(data); // Step 1: get index
    table[index].push_front(data); // Step 2: insert at front (O(1))
  }

  bool search(int data) {
    /**
     * Searches whether the data is in the hash table, if yes return true,
     * otherwise return false.
     *
     * This function will do the followings:
     * 1. hash the data key to get the appropriate index in the hash table
     * 2. to search for the data, you need to traverse the deque
     *
     *    If you use a STL deque, the first iterator will be
     * name_of_deque.begin(), the last iterator will be name_of_deque.end() In
     * our case, name_of_deque will be table[index], assuming index is the hash
     * value we get from the hash function.
     * 3. As mentioned in the point2, if the element is not found in the
     * deque/vector, the iterator will point to the last address of the
     * list/vector. so if the iterator is the end of the deque, this function
     * will return false, otherwise, it will return true (because it is pointing
     * to some found item).
     *
     */
    int index = hash_function(data); // Step 1: get index

    // Step 2: traverse the deque
    for (auto it = table[index].begin(); it != table[index].end(); it++) {
      if (*it == data) {
        return true; // found
      }
    }

    return false; // not found
  }

  void remove(int data) {
    /**
     * Removes the data if it exists in the deque, if it does not exist, end the
     * function. We still need to traverse the structure to locate the data
     * before we remove. If the iterator is the end of the deque, i.e. the data
     * does not exist, we don't need to do anything, otherwise, if the data
     * exists, we will use the name_of_deque.erase(iterator) to remove the data
     * in the hash table
     *
     */
    int index = hash_function(data); // Step 1: get index

    // Step 2: traverse to find element
    for (auto it = table[index].begin(); it != table[index].end(); it++) {
      if (*it == data) {
        table[index].erase(it); // remove element
        return; // stop after removal
      }
    }
  }

  void print_hash_table() {
    int num =
        to_string(size - 1)
            .length(); // because 10 is one digit 0-9, 100 is two digits 0-99
    for (int i = 0; i < size; i++) {
      printf("| %*d | -> ", num, i);
      for (auto it = table[i].begin(); it != table[i].end();
           it++) { // as long as it is not the deque.end(), then continue
        if (it != --(table[i].end()))
          cout << *it
               << " -> "; // pre-decrement to one before the end of the deque
        else
          cout << *it;
      }
      cout << endl;
    }
  }
};

#endif