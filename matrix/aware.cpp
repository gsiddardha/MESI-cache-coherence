#include <iostream>
#include <cstdlib>

#include "../Access.h"

using namespace std;

// External variables & functions
extern int matrix_n, matrix_m, matrix_p;
extern int A(int, int);
extern int B(int, int);

void cache_aware(int s) {
	int i, j, k, ibuf, jbuf, kbuf;

	int** C = new int*[matrix_n];
	for(i=0; i<matrix_n; i++) {
		C[i] = new int[matrix_p];
	}

	for(ibuf=0; ibuf<matrix_n/s; ibuf++)
		for(jbuf=0; jbuf<matrix_n/s; jbuf++)
			for(kbuf=0; kbuf<matrix_n/s; kbuf++)
				for(i=ibuf; i<min(ibuf+s-1,matrix_n); i++)
					for(j=jbuf; j<min(jbuf+s-1,matrix_n); j++)
						for(k=kbuf; k<min(kbuf+s-1,matrix_n); k++)
							C[i][j] += A(i,k)*B(k,j);

	for(i=0; i<matrix_n; i++) {
		for(j=0; j<matrix_p; j++)
			cout << "\t" << C[i][j];
		cout << endl;
	}
}
