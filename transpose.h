//Copyright Tiberiu-Mihnea Gutanu 311CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>

void transpose(int ***matrix, int *m, int *n)
{
	//aloc dinamic in memorie o matrice temporara
	int **temp = (int **)malloc(*n * sizeof(int *));

	//matricea temp va retine elementele transpusei matricii initiale
	for (int i = 0; i < *n; ++i) {
		temp[i] = (int *)malloc(*m * sizeof(int));
		for (int j = 0; j < *m; ++j)
			temp[i][j] = (*matrix)[j][i];
	}

	//eliberez matricea initiala pentru a putea realiza modificarile in-place
	for (int i = 0; i < *m; ++i)
		free((*matrix)[i]);
	free(*matrix);

	*matrix = (int **)malloc(*n * sizeof(int *));

	//matricea initiala va prelua elementele lui temp
	for (int i = 0; i < *n; ++i) {
		(*matrix)[i] = (int *)malloc(*m * sizeof(int));
		for (int j = 0; j < *m; ++j)
			(*matrix)[i][j] = temp[i][j];
	}

	//eliberez matricea temporara
	for (int i = 0; i < *n; ++i)
		free(temp[i]);
	free(temp);

	//actualizez dimensiunile
	int aux = *m;
	*m = *n;
	*n = aux;
}
