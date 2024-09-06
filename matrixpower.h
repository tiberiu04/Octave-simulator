//Copyright Tiberiu-Mihnea Gutanu 311CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>
#include "allocatematrix.h"
#include "freematrix.h"
#include "multiplymatrix.h"
#define MOD 10007
#ifndef MATRIXPOWER_H
#define MATRIXPOWER_H

void matrixpower(int **mat, int m, int put)
{
	int i, j;

	int **result = allocatematrix(m, m);
	//formez In-ul, matricea identitate
	for (i = 0; i < m; ++i) {
		for (j = 0; j < m; ++j)
			if (i == j)
				result[i][j] = 1;
			else
				result[i][j] = 0;
	}
	//aloc dinamic in memorie o matrice temporara
	int **mat1 = allocatematrix(m, m);
	//initializez mat1 cu valorile lui mat
	for (i = 0; i < m; ++i) {
		for (j = 0; j < m; ++j)
			mat1[i][j] = mat[i][j];
	}
	while (put > 0) {
		//verific paritatea puterii
		if (put % 2 == 1) {
			int **temp = allocatematrix(m, m);
			//rezultatul va fi mat1*temp
			multiplymatrix(result, mat1, temp, m);
			for (i = 0; i < m; ++i) {
				for (j = 0; j < m; ++j)
					result[i][j] = temp[i][j];
			}
			freematrix(temp, m);
		}
		int **temp = allocatematrix(m, m);
		//pentru put par rezultatul este mat1*mat1
		multiplymatrix(mat1, mat1, temp, m);
		for (i = 0; i < m; ++i) {
			for (j = 0; j < m; ++j)
				mat1[i][j] = temp[i][j];
		}
		//eliberez din memorie matricea temp
		freematrix(temp, m);
		put /= 2;
	}
	//fac modificare matricii mat cu matricea rezultat in-place
	for (i = 0; i < m; ++i) {
		for (j = 0; j < m; ++j)
			mat[i][j] = result[i][j];
	}
	freematrix(result, m);
	freematrix(mat1, m);
}

#endif
