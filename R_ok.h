//Copyright Tiberiu-Mihnea Gutanu 311CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>
#include "matrixpower.h"
#define MOD 10007
#ifndef R_OK_H
#define R_OK_H

void R_ok(int ***mem, int *u, int *v, int nr, int put, int ind)
{
	if (nr < 0 || nr >= ind)
		printf("No matrix with the given index\n");
	else if (put < 0)
		printf("Power should be positive\n");
	else if (v[nr] != u[nr])
		printf("Cannot perform matrix multiplication\n");
	else
		matrixpower(mem[nr], v[nr], put);
}

#endif
