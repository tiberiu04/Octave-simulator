//Copyright Tiberiu-Mihnea Gutanu 311CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>

void command_P(int nr, int *v, int *u, int ***mat, int ind)
{
	if (nr < 0 || nr >= ind) {
		printf("No matrix with the given index");
		printf("\n");
	} else {
		for (int i = 0; i < v[nr]; i++) {
			for (int j = 0; j < u[nr]; j++)
				printf("%d ", mat[nr][i][j]);
			printf("\n");
		}
	}
}
