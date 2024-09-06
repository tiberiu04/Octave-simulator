//Copyright Tiberiu-Mihnea Gutanu 311CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>
#ifndef FREEMATRIX_H
#define FREEMATRIX_H

void freematrix(int **matrix, int rows)
{
	for (int i = 0; i < rows; i++)
		free(matrix[i]);
	free(matrix);
}

#endif
