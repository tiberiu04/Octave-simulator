//Copyright Tiberiu-Mihnea Gutanu 311CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>
#ifndef COMMAND_C_H
#define COMMAND_C_H
#include "freematrix.h"
#include "read_vec.h"

void command_C(int ***mat, int *m1, int *n1, int *m, int *n, int nr, int ind)
{
	scanf("%d", m1);
	//citesc indecsii pentru linii
	int *v1 = read_vec(*m1);
	scanf("%d", n1);
	//citesc indecsii pentru coloane
	int *u1 = read_vec(*n1);
	//verific existenta matricii
	if (nr < 0 || nr >= ind) {
		printf("No matrix with the given index");
		printf("\n");
	} else {
		//aloc dinamic o matrice temporara
		int **temp = (int **)malloc(*m1 * sizeof(int *));
		for (int i = 0; i < *m1; i++)
			temp[i] = (int *)malloc(*n1 * sizeof(int));
		//initializez matricea temporara cu valorule matricii initiale
		for (int i = 0; i < *m1; i++) {
			for (int j = 0; j < *n1; j++)
				temp[i][j] = (*mat)[v1[i]][u1[j]];
		}
		freematrix(*mat, *m);
		*mat = temp;
		*m = *m1;
		*n = *n1;
	}
	//eliberez vectorii din indecsi caci nu imi mai trebuie
	free(v1);
	free(u1);
}

#endif
