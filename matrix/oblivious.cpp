#include <iostream>
#include <cstdlib>

#include "../Access.h"

using namespace std;

// External variables & functions
extern int matrix_n, matrix_m, matrix_p;
extern int A(int, int);
extern int B(int, int);

void recur_func(int, int, int, int, int, int, int);

void cache_oblivious(void) {
	int i, j, k;
	recur_func(matrix_n, matrix_m, matrix_p, 0, 0, 0, 0);
}

void recur_func(int n, int m, int p, int a1, int a2, int b1, int b2){
	if((n==1) && (m==1) && (p==1)){
		A(a1, a2)*B(b1, b2);
		return;
	}

	if((n >= m) && (n >= p)) {
		recur_func(n/2, m, p, a1, a2, b1, b2);
		recur_func((n - n/2), m, p, a1+n/2, a2, b1, b2);
	} else if((m >= n) && (m >= p)) {
		recur_func(n, m/2, p, a1, a2, b1, b2);
		recur_func(n, (m-m/2), p, a1, a2+m/2, b1+m/2, b2);
	} else if((p >= m) && (p >= n)) {
		recur_func(n, m, p/2, a1, a2, b1, b2);
		recur_func(n, m, (p-p/2), a1, a2, b1, b2+p/2);
	}
}
