//Copyright Tiberiu-Mihnea Gutanu 311CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>
#include "allocatematrix.h"
#include "callocatematrix.h"
#include "add.h"
#include "sub.h"
#include "freematrix.h"
#define MOD 10007
#ifndef STRASSEN_H
#define STRASSEN_H

int **strassen(int n, int **A, int **B, int **C)
{
	if (n == 1) {
		C[0][0] = (A[0][0] * B[0][0]) % MOD;
		if (C[0][0] < 0)
			C[0][0] += MOD;
	} else {
		int k = n / 2; //micsorez n-ul
		int **A11 = allocatematrix(k, k); //aloc in memorie mat. ajutatoare
		int **A12 = allocatematrix(k, k);
		int **A21 = allocatematrix(k, k);
		int **A22 = allocatematrix(k, k);
		int **B11 = allocatematrix(k, k);
		int **B12 = allocatematrix(k, k);
		int **B21 = allocatematrix(k, k);
		int **B22 = allocatematrix(k, k);
		int **C11 = allocatematrix(k, k);
		int **C12 = allocatematrix(k, k);
		int **C21 = allocatematrix(k, k);
		int **C22 = allocatematrix(k, k);
		int **P1 = callocatematrix(k, k);
		int **P2 = callocatematrix(k, k);
		int **P3 = callocatematrix(k, k);
		int **P4 = callocatematrix(k, k);
		int **P5 = callocatematrix(k, k);
		int **P6 = callocatematrix(k, k);
		int **P7 = callocatematrix(k, k);
		int **temp1 = callocatematrix(k, k);
		int **temp2 = callocatematrix(k, k);
		for (int i = 0; i < k; i++)
			for (int j = 0; j < k; j++) {
				A11[i][j] = A[i][j]; //initializez cele 8 matrici ajutatoare
				A12[i][j] = A[i][j + k];
				A21[i][j] = A[i + k][j];
				A22[i][j] = A[i + k][j + k];
				B11[i][j] = B[i][j];
				B12[i][j] = B[i][j + k];
				B21[i][j] = B[i + k][j];
				B22[i][j] = B[i + k][j + k];
			}
		strassen(k, add(k, A11, A22, temp1), add(k, B11, B22, temp2), P1);
		strassen(k, add(k, A21, A22, temp1), B11, P2); //calculez P-urile
		strassen(k, A11, sub(k, B12, B22, temp1), P3);
		strassen(k, A22, sub(k, B21, B11, temp1), P4);
		strassen(k, add(k, A11, A12, temp1), B22, P5);
		strassen(k, sub(k, A21, A11, temp1), add(k, B11, B12, temp2), P6);
		strassen(k, sub(k, A12, A22, temp1), add(k, B21, B22, temp2), P7);
		add(k, add(k, P1, P4, temp1), sub(k, P7, P5, temp2), C11);
		add(k, P3, P5, C12); //calculez blocurile matricii C
		add(k, P2, P4, C21);
		add(k, sub(k, P1, P2, temp1), add(k, P3, P6, temp2), C22);
		freematrix(temp1, k);
		freematrix(temp2, k);
		for (int i = 0; i < k; i++)
			for (int j = 0; j < k; j++) {
				C[i][j] = C11[i][j]; //imi formez matricea
				C[i][j + k] = C12[i][j];
				C[k + i][j] = C21[i][j];
				C[k + i][k + j] = C22[i][j];
			}
		freematrix(P1, k); //eliberez din memorie matricile tempoare
		freematrix(P2, k);
		freematrix(P3, k);
		freematrix(P4, k);
		freematrix(P5, k);
		freematrix(P6, k);
		freematrix(P7, k);
		freematrix(A11, k);
		freematrix(A12, k);
		freematrix(A21, k);
		freematrix(A22, k);
		freematrix(B11, k);
		freematrix(B12, k);
		freematrix(B21, k);
		freematrix(B22, k);
		freematrix(C11, k);
		freematrix(C12, k);
		freematrix(C21, k);
		freematrix(C22, k);
	}
	return C; //returnez valoarea ceruta
}

#endif
