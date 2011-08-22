#include <iostream>
#include <cstdlib>

#include "../Access.h"

using namespace std;

// External variables & functions
extern int matrix_n, matrix_m, matrix_p;
extern int A(int, int);
extern int B(int, int);

void cache_aware(int s);
void matrix_ord(int n, int m, int p, int i, int j, int k, int s);


void cache_aware(int s){
	int i, j, k;

	for(i = 0; i < matrix_n/s; i++)
		for(j = 0; j < matrix_m/s; j++)
			for(k = 0 ; k < matrix_p/s; k++)
				matrix_ord(matrix_n, matrix_m, matrix_p, i, k, j, s);
}

void matrix_ord(int n, int m, int p, int i, int j, int k, int s){
	int w, x, y;

	for(w=i*s; w < min(n, (i+1)*s); w++)
		for(x=j*s; x < min(m, (j+1)*s); x++)
			for(y=k*s; y < min(p, (k+1)*s); y++)
				A(w,y)*B(y,x);
}
