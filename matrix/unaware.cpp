#include <iostream>
#include <cstdlib>
#include "../Access.h"

using namespace std;

// External variables & functions
extern int matrix_n, matrix_m, matrix_p;
extern int A(int, int);
extern int B(int, int);

void cache_unaware(void) {
	int i, j, k;

	int** C = new int*[matrix_n];
	for(i=0; i<matrix_n; i++) {
		C[i] = new int[matrix_p];
	}

	for(i=0; i<matrix_n; i++) {
		for(j=0; j<matrix_p; j++) {
			for(k=0; k<matrix_m; k++)
				C[i][j] += A(i,k)*B(k,j);
			cout << "\t" << C[i][j];
		}
		cout << endl;
	}
}
