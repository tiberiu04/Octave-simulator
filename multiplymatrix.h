//Copyright Tiberiu-Mihnea Gutanu 311CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>
#define MOD 10007
#ifndef MULTIPLYMATRIX_H
#define MULTIPLYMATRIX_H

void multiplymatrix(int **A, int **B, int **result, int n)
{
	int i, j, k;

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			result[i][j] = 0;
			for (k = 0; k < n; ++k) {
				result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
				if (result[i][j] < 0)
					result[i][j] += MOD;
			}
		}
	}
}

#endif
