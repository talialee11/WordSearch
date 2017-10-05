//Talia Lee tl2db 3/12/17 hashTable.h Lab 106
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <vector>
#include <string>
using namespace std;

class HashTable{
 public:
  HashTable();
  void insert(string a);
  unsigned int hash(string str);
  unsigned int hash2(string str);
  bool contains(string b);
  void setSize(int c);
  
 private:
  vector <string> table;

};
#endif
