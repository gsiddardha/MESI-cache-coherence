#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include "Access.h"

using namespace std;

// External functions
extern void cache_unaware(void);
extern void cache_aware(int);
extern void cache_oblivious(void);

// Global variable declaration
Access* accessor;
int matrix_n, matrix_m, matrix_p;

// Function prototype declaration
int A(int x, int y);
int B(int x, int y);

int main(int argc, char** argv) {
	if(argc!=4) {
		cout << "Usage: " << argv[0] << " <cache_size_inKB> <block_size_inB> <associativity>\n";
		return 1;
	}

	// Declaring variables
	int i, j;
	ifstream inFile;
	
	// Opening files
	inFile.open("INPUT");
	
	// Checking for situation of files
	if(!inFile.is_open()) {
		cout << "Error while opening the input file" << endl;
		return 1;
	}

	// Reading matrix lengths
	inFile >> matrix_n >> matrix_m >> matrix_p;

	// Initialise accessor
	accessor = new Access(atoi(argv[1])*1024, atoi(argv[2]), atoi(argv[3]), (matrix_n+matrix_p)*matrix_m);

	// Reading matrices A & B
	for(i=0; i<matrix_n; i++)
		for(j=0; j<matrix_m; j++) {
			accessor->write(rand());
		}
	for(i=0; i<matrix_m; i++)
		for(j=0; j<matrix_p; j++) {
			accessor->write(rand());
		}

	// Cache Unaware matrix multiplication
	cache_unaware();
	accessor->print("unaware");

	// Restart Cache
	accessor->restart_cache();

	// Cache Aware matrix multiplication
	cache_aware(2);
	accessor->print("aware");

	// Restart Cache
	accessor->restart_cache();

	// Cache Oblivious matrix multiplicatio
	cache_oblivious();
	accessor->print("oblivious");

	// Closing files
	inFile.close();

	return 0;
}

int A(int x, int y) {
	return accessor->get(x*matrix_m+y);
}

int B(int x, int y) {
	return accessor->get(matrix_n*matrix_m+x*matrix_p+y);
}
