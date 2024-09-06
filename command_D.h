//Copyright Tiberiu-Mihnea Gutanu 311CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>

void command_D(int nr, int *v, int *u, int index)
{
	if (nr >= 0 && nr < index)
		printf("%d %d\n", v[nr], u[nr]);
	else
		printf("No matrix with the given index\n");
}
