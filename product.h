//Copyright Tiberiu-Mihnea Gutanu 311CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>
#define MOD 10007
#ifndef PRODUCT_H
#define PRODUCT_H

int **product(int **mat1, int m, int n, int **mat2, int p)
{
	int **result = NULL;
	result = (int **)malloc(m * sizeof(int *));
	for (int i = 0; i < m; i++)
		result[i] = (int *)malloc(p * sizeof(int));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			result[i][j] = 0;
			for (int k = 0; k < n; k++) {
				result[i][j] = (result[i][j] + mat1[i][k] * mat2[k][j]) % MOD;
				if (result[i][j] < 0)
					result[i][j] += MOD;
			}
		}
	}

	return result;
}

#endif
