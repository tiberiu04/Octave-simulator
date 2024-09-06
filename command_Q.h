//Copyright Tiberiu-Mihnea Gutanu 311CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>

void command_Q(int ***array3d, int index, int *v, int *u)
{
	//eliberez tot din memorie
	for (int i = 0; i < index; i++) {
		for (int j = 0; j < v[i]; j++)
			free(array3d[i][j]);
		free(array3d[i]);
	}
	free(array3d);
	free(v);
	free(u);
}
