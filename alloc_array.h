//Copyright Tiberiu-Mihnea Gutanu 311CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>
#ifndef ALLOC_ARRAY_H
#define ALLOC_ARRAY_H

void alloc_array(int **v, int **u, int m, int n, int index)
{
	int *w = (int *)realloc(*v, (index + 1) * sizeof(int));
	//verific daca realocarea a fost cu succes
	if (!w) {
		fprintf(stderr, "realloc() failed\n");
		*v = NULL;
		return;
	}
	*v = w;
	(*v)[index] = m;//initializez cu numarul de linii ale matricii

	int *q = (int *)realloc(*u, (index + 1) * sizeof(int));
	//verific daca realocarea a fost cu succes
	if (!q) {
		fprintf(stderr, "realloc() failed\n");
		*u = NULL;
		return;
	}
	*u = q;
	(*u)[index] = n;//initializez cu numarul de coloane ale matricii
}

#endif
