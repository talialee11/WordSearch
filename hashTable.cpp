//Talia Lee tl2db 3/12/17 hashTable.cpp Lab 106

#include "hashTable.h"
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

HashTable::HashTable(){
  setSize(0);
}

void HashTable::setSize(int size){
  table.resize(size,"");
}

unsigned int HashTable::hash(string str){
  unsigned int hash = 0;
  for (int x=0; x<str.length(); x++){
    hash += str.at(x)*pow(67,x);
  }
  return hash%table.size();
}

unsigned int HashTable::hash2(string str){
  unsigned int hash = 0;
  for (int x=0; x<str.length(); x++){
    hash += 13-(str.at(x)%7);
  }
  return hash;
}


void HashTable::insert(string a){
  int i = 1;
  
  unsigned int myhash = hash(a);
  unsigned int temp = myhash;
  while (table.at(temp) != ""){
    //temp = (myhash + (i*hash2(a)))%table.size();
    temp = (myhash + (i*i))%table.size();
    i++;
  }
  table.at(temp) = a;
}



bool HashTable::contains(string b){
  int i = 1;
  unsigned int myhash = hash(b);
  unsigned int temp = myhash;
  while (table.at(temp) != ""){
    if (table.at(temp) == b)
      return true;
    //temp = (myhash + (i*hash2(b)))%table.size();
    temp = (myhash + (i*i))%table.size();
    i++;
  }
  return false;
}


 


