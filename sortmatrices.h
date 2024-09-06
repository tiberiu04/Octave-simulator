//Copyright Tiberiu-Mihnea Gutanu 311CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>
#include "swapmatrices.h"
#include "suma.h"
#ifndef SORTMATRICES_H
#define SORTMATRICES_H

void sortmatrices(int ***mat, int index, int **v, int **u)
{
	int sum1, sum2;

	for (int i = 0; i < index; i++) {
		for (int j = i + 1; j < index; j++) {
			//calculez sumele pt ma[i] si ma[j] pentru a le putea compara
			sum1 = suma(mat[i], (*v)[i], (*u)[i]);
			sum2 = suma(mat[j], (*v)[j], (*u)[j]);

			if (sum1 > sum2) {
				swapmatrices(mat, i, j);
				int aux;
				aux = (*v)[i];
				(*v)[i] = (*v)[j];
				(*v)[j] = aux;
				aux = (*u)[i];
				(*u)[i] = (*u)[j];
				(*u)[j] = aux;
			}
		}
	}
}

#endif
