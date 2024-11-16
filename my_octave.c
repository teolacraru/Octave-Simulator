// Copyright 2023 Lacraru Teodora-Ioana 311CA 2023-2024
#include <stdio.h>
#include <stdlib.h>
#define MOD 10007

// functie care citeste elementele unei matrice
void read_matrix(int **matrice, int m, int n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &matrice[i][j]);
	}
}

// elibereaza memoria alocata
void free_mat(int ***matrice, int n)
{
	for (int i = 0; i < n; i++)
		free((*matrice)[i]);
	free(*matrice);
}

// functie ce interschimba doua matrice
void swap_matrice2(int ***a, int ***b)
{
	int **aux = *a;
	*a = *b;
	*b = aux;
}

// functia care afiseaza dimensiunile unei matrice ce are un anumit index
void D(int k, int *linii, int *coloane)
{
	int index;
	scanf("%d", &index);
	if (index >= 0 && index < k)
		printf("%d %d\n", linii[index], coloane[index]);
	else
		printf("No matrix with the given index\n");
}

// functia care afiseaza matricea index
void P(int k, int *m, int *n, int ***matrice_memorie)
{
	int index, linii, coloane;
	scanf("%d", &index);
	if (index >= 0 && index < k) {
		linii = m[index];
		coloane = n[index];
		int **matrix = matrice_memorie[index];
		for (int i = 0; i < linii; i++) {
			for (int j = 0; j < coloane; j++)
				printf("%d ", matrix[i][j]);
			printf("\n");
		}
	} else {
		printf("No matrix with the given index\n");
	}
}

// functia ce inmulteste 2 matrice din memorie
void M(int *k, int **m, int **n, int ****matrice_memorie)
{
	int im1, im2;
	scanf("%d %d", &im1, &im2);
	int l1 = (*m)[im1], l2 = (*m)[im2], c1 = (*n)[im1],
			c2 = (*n)[im2];
	if (c1 == l2 && im1 >= 0 && im1 < *k && im2 >= 0 && im2 < *k) {
		*m = realloc(*m, (*k + 1) * sizeof(int));
		(*m)[*k] = l1;
		*n = realloc(*n, (*k + 1) * sizeof(int));
		(*n)[*k] = c2;
		*matrice_memorie =
		realloc(*matrice_memorie, (*k + 1) * sizeof(int **));
		//aloc memorie pentru matricea rezultata care va avea numarul de linii
		// egal cu cel din prima matrice si cel de coloane egal cu cel din
		// a doua matrice
		(*matrice_memorie)[*k] = calloc(l1, sizeof(int *));
		for (int i = 0; i < l1; i++)
			(*matrice_memorie)[*k][i] = calloc(c2, sizeof(int));

		for (int i = 0; i < l1; i++) {
			for (int j = 0; j < c2; j++) {
				for (int q = 0; q < c1; q++)
					(*matrice_memorie)[*k][i][j] =
					((*matrice_memorie)[*k][i][j] +
					((*matrice_memorie)[im1][i][q] *
					(*matrice_memorie)[im2][q][j]) %
						MOD) % MOD;
			}
		}
		for (int i = 0; i < l1; i++) {
			for (int j = 0; j < c2; j++) {
				if ((*matrice_memorie)[*k][i][j] < 0)
					(*matrice_memorie)[*k][i][j] += MOD;
			}
		}
		*k = *k + 1;
	} else {
		if (c1 != l2 && im1 >= 0 && im1 < *k && im2 >= 0 && im2 < *k)
			printf("Cannot perform matrix multiplication\n");
		else
			printf("No matrix with the given index\n");
	}
}

// functia ce calculeaza suma elem unei matrice
int suma_elem(int k, int *m, int *n, int ***matrice_memorie)
{
	int s = 0;
	for (int i = 0; i < m[k]; i++) {
		for (int j = 0; j < n[k]; j++)
			s = s + matrice_memorie[k][i][j];
	}
	s = s % MOD;
	if (s < 0)
		s = s + MOD;
	return s;
}

// functie de interschimba val dintr un vector
void swapp(int *v, int m1, int m2)
{
	int aux;
	aux = v[m1];
	v[m1] = v[m2];
	v[m2] = aux;
}

// sorteaza matricele dupa suma elementelor
void O(int k, int *m, int *n, int ****matrice_memorie)
{
	int **tmp;
	for (int i = 0; i + 1 < k; i++) {
		for (int j = i + 1; j < k; j++) {
			if (suma_elem(i, m, n, *matrice_memorie) >
					suma_elem(j, m, n, *matrice_memorie)) {
				tmp = (*matrice_memorie)[i];
				(*matrice_memorie)[i] = (*matrice_memorie)[j];
				(*matrice_memorie)[j] = tmp;
				swapp(m, i, j);
				swapp(n, i, j);
			}
		}
	}
}

int **mem(int m, int n)
{
	int **mtr = malloc(m * sizeof(int *));
	for (int i = 0; i < m; i++)
		mtr[i] = malloc(n * sizeof(int));
	return mtr;
}

// redimensioneaza matricea
void C(int ***matrice_memorie, int *m, int *n, int k)
{
	int index, linii, coloane, **matrix, *idx_l, *idx_c, tmp;
	scanf("%d", &index);
	if (index < 0 || index >= k) {
		scanf("%d", &linii);
		idx_l = malloc(linii * sizeof(int));
		for (int i = 0; i < linii; i++)
			scanf("%d", &idx_l[i]);
		scanf("%d", &coloane);
		idx_c = malloc(coloane * sizeof(int));
		for (int i = 0; i < coloane; i++)
			scanf("%d", &idx_c[i]);
		// citesc toti indicii, chiar daca indexul nu este valid
		printf("No matrix with the given index\n");
		free(idx_c);
		free(idx_l);
	} else {
		scanf("%d", &linii);
		idx_l = malloc(linii * sizeof(int));
		for (int i = 0; i < linii; i++)
			scanf("%d", &idx_l[i]);
		scanf("%d", &coloane);
		idx_c = malloc(coloane * sizeof(int));
		for (int i = 0; i < coloane; i++)
			scanf("%d", &idx_c[i]);
		// citesc indicii corespunzatori redimensionarii
		tmp = m[index];
		m[index] = linii;
		n[index] = coloane;
		// matrix este matricea auxiliara
		matrix = mem(linii, coloane);
		for (int i = 0; i < linii; i++) {
			for (int j = 0; j < coloane; j++)
				matrix[i][j] = matrice_memorie[index][idx_l[i]][idx_c[j]];
		}
		free_mat(&matrice_memorie[index], tmp);
		matrice_memorie[index] = mem(linii, coloane);
		swap_matrice2(&matrice_memorie[index], &matrix);
		free_mat(&matrix, linii);
		free(idx_c);
		free(idx_l);
	}
}

// functie pentru memoria unei matrice
int **empty_mat(int n, int m)
{
	int **aux = calloc(n, sizeof(int *));
	for (int i = 0; i < n; i++)
		aux[i] = calloc(m, sizeof(int));
	return aux;
}

// functie ce transpune o matrice
void T(int k, int *m, int *n, int ***matrice_memorie)
{
	int index, **maux;
	scanf("%d", &index);
	if (index < 0 || index >= k) {
		printf("No matrix with the given index\n");
	} else {
		int mi = m[index];
		int ni = n[index];
		maux = mem(ni, mi);
		// maux este matricea auxiliara in care voi retina transpusa
		for (int i = 0; i < m[index]; i++) {
			for (int j = 0; j < n[index]; j++)
				maux[j][i] = matrice_memorie[index][i][j];
		}
		free_mat(&matrice_memorie[index], m[index]);
		matrice_memorie[index] = mem(n[index], m[index]);
		swap_matrice2(&matrice_memorie[index], &maux);
		// mut elementele din maux in matrice_memorie[index]
		m[index] = ni;
		n[index] = mi;
		free_mat(&maux, ni);
	}
}

int **I(int n)
{
	// functie ce creeaza matricea identitate
	int **aux = empty_mat(n, n);
	for (int i = 0; i < n; i++)
		aux[i][i] = 1;
	return aux;
}

// functie ce inmulteste 2 matrice
void **inmultire(int ***rez, int **matrice1, int **matrice2, int n)
{
	int **aux = empty_mat(n, n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++) {
				aux[i][j] = (aux[i][j] + matrice1[i][k] * matrice2[k][j]) % MOD;
				if (aux[i][j] < 0)
					aux[i][j] = aux[i][j] + MOD;
			}
	swap_matrice2(rez, &aux);
	free_mat(&aux, n);
	return 0;
}

// functie pentru ridicarea la putere
void R(int ***matrice_memorie, int *m, int *n, int k)
{
	int index, power, **m_rezultat, **m_initiala;
	scanf("%d%d", &index, &power);
	m_rezultat = I(m[index]);
	m_initiala = empty_mat(m[index], m[index]);
	int mi = m[index];
	for (int i = 0; i < mi; i++) {
		for (int j = 0; j < mi; j++)
			m_initiala[i][j] = matrice_memorie[index][i][j];
	}
	// in m_intiala retin matricea pe care vreau sa o ridic la putere
	if (index < 0 || index >= k) {
		printf("No matrix with the given index\n");
	} else {
		if (power < 0) {
			printf("Power should be positive\n");
		} else {
			if (m[index] != n[index]) {
				printf("Cannot perform matrix multiplication\n");
			} else {
				// cand puterea este para, ridic matricea obtinuta la puterea
				// 2 si
				// impart power la 2, altfel o inmultesc cu cea initiala
				while (power) {
					if (power % 2) {
						inmultire(&m_rezultat, m_rezultat, m_initiala, mi);
						power--;
					} else {
						inmultire(&m_initiala, m_initiala, m_initiala, mi);
						power = power / 2;
					}
				}
				swap_matrice2(&matrice_memorie[index], &m_rezultat);
			}
		}
	} // eliberez resursele
	free_mat(&m_rezultat, mi);
	free_mat(&m_initiala, mi);
}

void swap_val(int *v, int val1, int val2)
{
	int aux;
	aux = v[val1];
	v[val1] = v[val2];
	v[val2] = aux;
}

// elimina o matrice din memorie
void F(int ****matrice_memorie, int *m, int *n, int *k)
{
	int index, **aux;
	scanf("%d", &index);
	if (index < 0 || index >= *k) {
		printf("No matrix with the given index\n");
	} else {
		for (int p = index; p < *k - 1; p++) {
			aux = (*matrice_memorie)[p];
			(*matrice_memorie)[p] = (*matrice_memorie)[p + 1];
			(*matrice_memorie)[p + 1] = aux;
			swap_val(m, p, p + 1);
			swap_val(n, p, p + 1);
		}
		(*k)--;
	}
}

// eliberarea resurselor
void Q(int ***matrice_memorie, int *m, int *n, int k)
{
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n[i]; j++)
			free(matrice_memorie[i][j]);
		free(matrice_memorie[i]);
	}
	free(matrice_memorie);
	free(m);
	free(n);
}

int main(void)
{
	char litera;
	int ok = 0;
	int m, n, ***matrice_memorie, k = 0, *coloane, *linii;
	matrice_memorie = malloc(1 * sizeof(int **));
	coloane = malloc(1 * sizeof(int));
	linii = malloc(1 * sizeof(int));
	while (1) {
		scanf("%c", &litera);
		ok = 0;
		if (litera == 'L') {
			ok = 1;
			scanf("%d %d", &m, &n);
			matrice_memorie =
			realloc(matrice_memorie, (k + 1) * sizeof(int **));
			matrice_memorie[k] = malloc(m * sizeof(int **));
			for (int i = 0; i < m; i++)
				matrice_memorie[k][i] = malloc(n * sizeof(int));
			coloane = realloc(coloane, (k + 1) * sizeof(int));
			coloane[k] = n;
			linii = realloc(linii, (k + 1) * sizeof(int));
			linii[k] = m;
			read_matrix(matrice_memorie[k], m, n);
			k++; // actualizez nr de matrice din memorie
		}
		if (litera == 'D')
			D(k, linii, coloane), ok = 1;
		if (litera == 'P')
			P(k, linii, coloane, matrice_memorie), ok = 1;
		if (litera == 'M')
			M(&k, &linii, &coloane, &matrice_memorie), ok = 1;
		if (litera == 'O')
			O(k, linii, coloane, &matrice_memorie), ok = 1;
		if (litera == 'T')
			T(k, linii, coloane, matrice_memorie), ok = 1;
		if (litera == 'R')
			R(matrice_memorie, linii, coloane, k), ok = 1;
		if (litera == 'F') {
			ok = 1;
			int a = n;
			F(&matrice_memorie, linii, coloane, &k);
			if (a != n)
				free_mat(&matrice_memorie[k], linii[k]);
		}
		if (litera == 'S')
			M(&k, &linii, &coloane, &matrice_memorie), ok = 1;
		if (litera == 'C')
			C(matrice_memorie, linii, coloane, k), ok = 1;
		if (litera == 'Q') {
			Q(matrice_memorie, coloane, linii, k), ok = 1;
			break;
		}
		if (ok == 0 && litera != '\n')
			printf("Unrecognized command\n");
	}
	return 0;
}
