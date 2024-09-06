//Copyright Tiberiu-Mihnea Gutanu 311CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>
#ifndef READ_VEC_H
#define READ_VEC_H

int *read_vec(int n)
{
	//aloc dinamic in memorie un vector de dimensiune n
	int *v = (int *)malloc(n * sizeof(int));

	//verific daca alocarea a fost cu succes
	if (!v) {
		fprintf(stderr, "malloc() failed\n");
		return NULL;
	}

	//citesc vectorul
	for (int i = 0; i < n; ++i)
		scanf("%d", &v[i]);
	return v;
}

#endif
