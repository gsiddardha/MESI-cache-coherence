#include <iostream>
#include <cstdlib>

#include "../Access.h"

using namespace std;

// External variables & functions
extern int matrix_n, matrix_m, matrix_p;
extern int A(int, int);
extern int B(int, int);

void ord_matrix_multi(int, int, int, int);

void cache_aware(int s){
	for(int i=0; i<=matrix_n/s; i++)
		for(int j=0; j<=matrix_m/s; j++)
			for(int k=0; k<=matrix_p/s; k++)
				ord_matrix_multi(i, j, k, s);
}

void ord_matrix_multi(int i, int j, int k, int s){
	for(int x=i*s; x < min(matrix_n, (i+1)*s); x++)
		for(int y=j*s; y < min(matrix_m, (j+1)*s); y++)
			for(int z=k*s; z < min(matrix_p, (k+1)*s); z++)
				A(x,y)*B(y,z);
}
