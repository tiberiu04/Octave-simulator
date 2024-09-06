//Copyright Tiberiu-Mihnea Gutanu 311CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>
#include "alloc_array.h"
#include "allocatematrix.h"
#include "strassen.h"
#define MOD 10007
#ifndef OKSTRASSEN_H
#define OKSTRASSEN_H

void okstrassen(int p, int q, int ****a, int **v, int **u, int *ind, int *cap)
{
	//verific existenta matricilor
	if ((p < 0 || p >= *ind) || (q < 0 || q >= *ind)) {
		printf("No matrix with the given index");
		printf("\n");
	} else if ((*u)[p] == (*v)[p] && (*u)[q] == (*v)[p] && (*u)[p] == (*v)[q]) {
		if (*ind == *cap) {
			*cap *= 2;
			*a = (int ***)realloc(*a, *cap * sizeof(int **));
		}
		//am verificat daca se va iesi din memorie
		//aloc dinamic noile dimensiuni
		alloc_array(&(*v), &(*u), (*v)[p], (*v)[p], *ind);
		(*ind)++;
		//aloc dinamic matricea a[ind - 1] care va retine matricea produs
		(*a)[*ind - 1] = allocatematrix((*v)[p], (*v)[p]);
		(*a)[*ind - 1] = strassen((*v)[p], (*a)[p], (*a)[q], (*a)[*ind - 1]);
	} else {
		printf("Cannot perform matrix multiplication");
		printf("\n");
	}
}

#endif
