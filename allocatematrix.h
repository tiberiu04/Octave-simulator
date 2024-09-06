//Copyright Tiberiu-Mihnea Gutanu 311CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>
#ifndef ALLOCATEMATRIX_H
#define ALLOCATEMATRIX_H

int **allocatematrix(int rows, int cols)
{
	int **matrix;
	//aloc dinamic in memorie o matrice
	int **a = (int **)malloc(rows * sizeof(int *));
	if (!a) { // daca nu pot aloca, opresc executia si afisez un mesaj
		fprintf(stderr, "malloc() for matrix failed\n");
		*matrix = NULL;
		return NULL;
	}

	matrix = a;

	for (int i = 0; i < rows; i++) {
		a[i] = (int *)malloc(cols * sizeof(int));
		if (!a[i]) {
			// daca una din alocari a esuat, trebuie sa dezaloc tot ce am alocat
			fprintf(stderr, "malloc() for line %d failed\n", i);
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
