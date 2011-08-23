#include <iostream>
#include <cstdlib>
#include "../Access.h"

using namespace std;

// External variables & functions
extern int matrix_n, matrix_m, matrix_p;
extern int A(int, int);
extern int B(int, int);

void cache_unaware(void) {
	for(int i=0; i<matrix_n; i++)
		for(int j=0; j<matrix_p; j++)
			for(int k=0; k<matrix_m; k++)
				A(i,k)*B(k,j);
}
