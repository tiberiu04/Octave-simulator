//Copyright Tiberiu-Mihnea Gutanu 311CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>
#define MOD 10007
#ifndef SUMA_H
#define SUMA_H

int suma(int **matrix, int m, int n)
{
	int s = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			s = (s + matrix[i][j]) % MOD;
	}
	if (s < 0)
		s = s + MOD;
	return s;
}

#endif
