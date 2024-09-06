//Copyright Tiberiu-Mihnea Gutanu 311CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>
#ifndef SWAPMATRICES_H
#define SWAPMATRICES_H

void swapmatrices(int ***matrixarray, int i, int j)
{
	int **temp = matrixarray[i];
	matrixarray[i] = matrixarray[j];
	matrixarray[j] = temp;
}

#endif
