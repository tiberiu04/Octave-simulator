//Copyright Tiberiu-Mihnea Gutanu 311CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>
#include "freematrix.h"
#ifndef COMMAND_F_H
#define COMMAND_F_H

void command_F(int ***array3d, int *index, int nr, int **v, int **u)
{
	//eliberez din memorie matricea de index nr
	freematrix(array3d[nr], (*v)[nr]);
	//mut elementele din vectori cu o pozitie la stanga
	for (int i = nr; i < *index - 1; i++) {
		array3d[i] = array3d[i + 1];
		(*v)[i] = (*v)[i + 1];
		(*u)[i] = (*u)[i + 1];
	}
	(*index)--;
}

#endif
