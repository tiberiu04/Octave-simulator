//Copyright Tiberiu-Mihnea Gutanu 311CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "alloc_array.h"
#include "command_D.h"
#include "command_P.h"
#include "allocatematrix.h"
#include "readmatrix.h"
#include "freematrix.h"
#include "callocatematrix.h"
#include "read_vec.h"
#include "command_C.h"
#include "suma.h"
#include "swapmatrices.h"
#include "sortmatrices.h"
#include "transpose.h"
#include "product.h"
#include "multiplymatrix.h"
#include "matrixpower.h"
#include "R_ok.h"
#include "command_F.h"
#include "add.h"
#include "sub.h"
#include "okstrassen.h"
#include "command_Q.h"
#define MOD 10007

int main(void)
{
	int n, m, nr = 0, p, p1, p2, ind = 0, cap = 2, m1, n1, put;
	int *v = NULL, *u = NULL, ***mem = NULL;
	char command = '\0';
	mem = (int ***)malloc(cap * sizeof(int **)); //aloc in memorie vectorul 3d
	while (command != 'Q') {
		scanf(" %c", &command);
		if (command == 'L') {
			if (scanf("%d %d", &m, &n) == 2 && ind == cap)
				mem = (int ***)realloc(mem, (cap *= 2) * sizeof(int **));
			alloc_array(&v, &u, m, n, ind);//aloc in memorie dimensiunile
			mem[ind] = allocatematrix(m, n);//aloc in memorie a ind-a matrice
			readmatrix(mem[ind], m, n);
			ind++;
		} else if (command == 'D') {
			scanf("%d", &nr);
			command_D(nr, v, u, ind);
		} else if (command == 'P') {
			scanf("%d", &nr);
			command_P(nr, v, u, mem, ind);
		} else if (command == 'T') {
			scanf("%d", &nr);
			if (nr >= 0 && nr < ind)//verific existenta matricii
				transpose(&mem[nr], &v[nr], &u[nr]);//transpun matricea
			else
				printf("No matrix with the given index\n");
		} else if (command == 'M') {
			scanf("%d %d", &p1, &p2);
			if (p1 < 0 || p2 < 0 || p1 > ind || p2 > ind) {
				printf("No matrix with the given index");
				printf("\n"); //verific existenta matricilor
			} else {
				if (u[p1] != v[p2]) {//verific conditia pentru inmultire
					printf("Cannot perform matrix multiplication");
					printf("\n");
				} else if (u[p1] == v[p2]) {
					m = v[p1], n = u[p1], p = u[p2];
					if (ind == cap) {
						cap *= 2;//maresc capacitatea veccoturlui
						mem = (int ***)realloc(mem, cap * sizeof(int **));
					}
					mem[ind] = product(mem[p1], m, n, mem[p2], p);//initializez
					if (mem[ind])
						alloc_array(&v, &u, m, p, ind++);//retin dimensiunile
				}
			}
		} else if (command == 'O') {
			nr = ind;
			sortmatrices(mem, nr, &v, &u);//apelez subprogramul pentru sortare
		} else if (command == 'C') {
			scanf("%d", &nr);//citesc indexul
			command_C(&mem[nr], &m1, &n1, &v[nr], &u[nr], nr, ind);
		} else if (command == 'R') {
			scanf("%d %d", &nr, &put);
			R_ok(mem, u, v, nr, put, ind);
		} else if (command == 'F') {
			scanf("%d", &nr);
			if (nr < 0 || nr >= ind) {//verific daca exista matricea
				printf("No matrix with the given index");
				printf("\n");
			} else {
				command_F(mem, &ind, nr, &v, &u);
				if (ind > 0 && ind <= cap / 2) {
					cap /= 2;//injumatatesc capacitatea
					mem = (int ***)realloc(mem, cap * sizeof(int **));
				}
			}
		} else if (command == 'S') {
			scanf("%d %d", &p1, &p2);
			okstrassen(p1, p2, &mem, &v, &u, &ind, &cap);
		} else if (command == 'Q') {
			nr = ind;
			command_Q(mem, ind, v, u);//eliberez toate resursele din memorie
		} else {
			printf("Unrecognized command");
			printf("\n");
		}
	}
	return 0;
}
