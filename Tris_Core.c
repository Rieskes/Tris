#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tris.c"
#include "fonctionAff&Validation.c"
#include "protoFonction.h"
#define N 10000

int main()
{
	int T[N];
	int n = N;
	float tabClock[36];
	int nbTri = 6;
	int * tabTrie;
	int choixMenu;
	void(*tabFonction[])(int[], int) = { triParInsertion, triParSelection, triParEchange, ShellSort, heapsort, quickSort };
	char * tabNomTri[6] = { "Tri Par Insertion", "Tri Par Selection", "Tri Par Echange", "ShellSort", "Heapsort", "QuickSort" };

	printf("Version programme : O.9.02\n");

	printf("Taper 1 pour trier des tableaux tries, 2 pour des tableaux non triés et 3 pour faire les deux \n");
	scanf("%d", &choixMenu);

	if (choixMenu == 1 || choixMenu == 3)
	{
		generationTable(T, n);

		tabTrie = malloc(n * sizeof(int));

		for (int j = 0; j < n; j++)
			tabTrie[j] = T[j];

		triParInsertion(tabTrie, n);

		triTable(tabTrie, n, tabFonction, tabClock, tabNomTri, nbTri, 1);
		slowerFaster(tabClock, tabNomTri, nbTri);

	}


	if (choixMenu == 2 || choixMenu == 3)
	{
		printf("\n\nTris de tableaux non triés : \n");

		generationTable(T, n);
		triTable(T, n, tabFonction, tabClock, tabNomTri, nbTri, 10);
		slowerFaster(tabClock, tabNomTri, nbTri);
	}


	return EXIT_SUCCESS;
}


void generationTable(int T[], int n)
{
	srand(time(NULL));

	for (int i = 0; i < n; i++)
		T[i] = rand() % N;
}
