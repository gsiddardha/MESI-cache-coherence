#include <iostream>
#include <cstdlib>
#include <cmath>
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
	if(argc!=7) {
		cout << "Usage: " << argv[0] << " <cache_size_inKB> <block_size_inB> <associativity> <matrix_n> <matrix_m> <matrix_p>\n";
		return 1;
	}

	// Reading matrix lengths
	matrix_n = atoi(argv[4]);
	matrix_m = atoi(argv[5]);
	matrix_p = atoi(argv[6]);

	// Initialise accessor
	accessor = new Access(atoi(argv[1])*1024, atoi(argv[2]), atoi(argv[3]), (matrix_n+matrix_p)*matrix_m);

	// Reading matrices A & B
	for(int i=0; i<matrix_n; i++)
		for(int j=0; j<matrix_m; j++) {
			accessor->write(rand());
		}
	for(int i=0; i<matrix_m; i++)
		for(int j=0; j<matrix_p; j++) {
			accessor->write(rand());
		}

	// Starting Ouput
	cout << "\tCache size: " << argv[1] << " KB" << endl;
	cout << "\tBlock size: " << argv[2] << " B" << endl;
	cout << "\tAssociativity: " << argv[3] << endl;
	cout << endl;
	cout << "\tMatrix n: " << argv[4] << endl;
	cout << "\tMatrix m: " << argv[5] << endl;
	cout << "\tMatrix p: " << argv[6] << endl;

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

	cout << endl;

	return 0;
}

int A(int x, int y) {
	return accessor->get(x*matrix_m+y);
}

int B(int x, int y) {
	return accessor->get(matrix_n*matrix_m+x*matrix_p+y);
}
