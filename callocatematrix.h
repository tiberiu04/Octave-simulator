//Copyright Tiberiu-Mihnea Gutanu 311CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>
#ifndef CALLOCATEMATRIX_H
#define CALLOCATEMATRIX_H

int **callocatematrix(int rows, int cols)
{
	int **matrix;
	//aloc dinamic in memorie o matrice
	int **a = (int **)calloc(rows, sizeof(int *));
	if (!a) { // daca nu pot aloca, opresc executia si afisez un mesaj
		fprintf(stderr, "calloc() for matrix failed\n");
		*matrix = NULL;
		return NULL;
	}

	matrix = a;

	for (int i = 0; i < rows; i++) {
		a[i] = (int *)calloc(cols, sizeof(int));
		if (!a[i]) {
			// daca una din alocari a esuat, trebuie sa dezaloc tot ce am alocat
			fprintf(stderr, "calloc() for line %d failed\n", i);
			for (int j = 0; j < i; j++) {
				free(a[j]);
			}
			free(a);
			*matrix = NULL;
			return NULL;
		}
	}

	return matrix;
}

#endif
