#include <iostream>
#include <cstdlib>
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
	if(argc!=5) {
		cout << "Usage: " << argv[0] << "<cache_size_inKB> <block_size_inB> <associativity> <memory_size_inKB>\n";
		return 1;
	}

	// Declaring variables
	int i, j, buf;
	ifstream inFile;
	
	// Opening files
	inFile.open("INPUT");
	
	// Checking for situation of files
	if(!inFile.is_open()) {
		cout << "Error while opening the input file" << endl;
		return 1;
	}

	// Initialise accessor
	accessor = new Access(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));

	// Reading matrix lengths
	inFile >> matrix_n >> matrix_m >> matrix_p;

	// Reading matrices A & B
	for(i=0; i<matrix_n; i++)
		for(j=0; j<matrix_m; j++) {
			inFile >> buf;
			accessor->write(buf);
		}
	for(i=0; i<matrix_m; i++)
		for(j=0; j<matrix_p; j++) {
			inFile >> buf;
			accessor->write(buf);
		}

	// Cache Unaware matrix multiplication
	cout << "Cache Unaware:" << endl;
	cache_unaware();
	cout << endl << "\tCache Statistics:" << endl << endl;

	// Cache Aware matrix multiplication
	cout << "Cache Aware:" << endl;
	cache_aware(atoi(argv[2])/4);
	cout << endl << "\tCache Statistics:" << endl << endl;

	// Cache Oblivious matrix multiplication
	cout << "Cache Oblivious:" << endl;
	cache_oblivious();
	cout << endl << "\tCache Statistics:" << endl << endl;

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
