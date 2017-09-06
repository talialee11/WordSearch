//Talia Lee tl2db 3/12/17 wordPuzzle.cpp Lab 106

#include "hashTable.h"
#include "timer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;


// We create a 2-D array of some big size, and assume that the grid
// read in will be less than this size (a valid assumption for lab 6)
#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];
HashTable table;
HashTable prefix;

// Forward declarations
bool readInGrid (string filename, int &rows, int &cols);
bool readInDict (string filename);
char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);


bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}

/** The main() function shows how to call both the readInGrid()
 * function as well as the getWordInGrid() function.
 */
int main(int argc, char* argv[]) {
    int rows, cols;
    int total = 0;
    timer t;
    bool result = readInGrid (argv[2], rows, cols);
    bool r = readInDict(argv[1]);    
         string directions[8] = {"N ", "NE" , "E " , "SE" , "S ", "SW" , "W ", "NW"};
    string w;
    t.start();
    if (result == true && r == true){
      for (int x=0; x<cols; x++){
	for (int y=0; y<rows; y++){
	  for (int dir=0; dir<8; dir++){
	    for (int len=3; len<=22; len++){
	      string b = getWordInGrid(y,x,dir,len,rows,cols);
	      if(b.length() != len){
		break;
	      }
	      if (!prefix.contains(b)){
		break;
	      }
	      if (table.contains(b)){
		total++;
		//cout<< directions[dir] << "("<<y<<", "<<x<<"):     "<<getWordInGrid(y,x,dir,len,rows,cols)<<"\n";
	       w+= directions[dir] + "("+to_string(y)+", "+to_string(x)+"):     "+b+"\n";
		
	      }
	    }
	  }
	}
      }
    }
    t.stop();
    cout<<w<<endl;
    cout << total << " words found" << endl;
    cout<< "Found all words in " <<t.getTime()<< " seconds"<<endl;
    int time = t.getTime()*1000;
    cout<<time<<endl;
    return 0;
}


bool readInDict (string filename){
  string line;
  int count = 0;
  int count2 = 0;
  ifstream file(filename.c_str());
  
  if ( !file.is_open() )
    return false;
      
while (getline(file,line)){
  count ++;
  for (int x = 3; x<=line.length();x++){
    count2++;
    }
 }
 file.close();
 
 ifstream file2(filename.c_str());
 table.setSize(getNextPrime(count*2));
 prefix.setSize(getNextPrime(count2*2));
 while (getline(file2,line)){
   table.insert(line);
   for (int y = 3; y<=line.length(); y++){
     prefix.insert(line.substr(0,y));
   }
 }
 return true;
}

bool readInGrid (string filename, int &rows, int &cols) {
    string line;

    ifstream file(filename.c_str());

    if ( !file.is_open() )
        return false;

    file >> rows;
    getline (file,line); 
    file >> cols;
    getline (file,line);
    getline (file,line);

    file.close();
    int pos = 0; 
    for ( int r = 0; r < rows; r++ ) {
        for ( int c = 0; c < cols; c++ ) {
            grid[r][c] = line[pos++];
	    //cout << grid[r][c];
        }
	//cout<<endl;
    }
    return true;
}


char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols) {
   
    static char output[256];

    if ( len >= 255 )
        len = 255;
   
    int pos = 0, r = startRow, c = startCol;

    for ( int i = 0; i < len; i++ ) {

        if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) )
            break;

        output[pos++] = grid[r][c];
        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    // set the next character to zero (end-of-string)
    output[pos] = 0;
    // return the string (a C-style char* string, not a C++ string
    // object)
    return output;
}
