//Copyright Tiberiu-Mihnea Gutanu 311CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>
#define MOD 10007
#ifndef SUB_H
#define SUB_H

int **sub(int n, int **A, int **B, int **C)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			C[i][j] = (A[i][j] - B[i][j]) % MOD;
			if (C[i][j] < 0)
				C[i][j] += MOD;
		}
	return C;
}

#endif
