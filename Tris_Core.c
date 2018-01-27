#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tris.c"
#include "fonctionAff&Validation.c"
#include "protoFonction.h"
#define N 10000
#define nbTri 7

int main()
{
	int T[N];
	int n = N;
	float tabClockTri[42];
	/*Tableau pointeur de fonction*/
	void(*tabFonction[])(int[], int) = { triParInsertion, triParSelection, triParEchange, ShakeSort, ShellSort, heapsort, quickSort };
	/*Tableau nom des tris*/
	char * tabNomTri[nbTri] = { "Tri Par Insertion", "Tri Par Selection", "Tri Par Echange", "ShakeSort\t", "ShellSort\t", "Heapsort\t", "QuickSort\t" };

	/*Version programme*/
	printf("Version programme : 0.9.02\n\n");

	char recommencer[] = { 'O' };

	/*Choix tri sur tableau trié ou non trié*/
	generationTable(T, n);
	int *tabTrie = generationTableTriee(T, n);
	tabTrie[n];


	while (recommencer[0] != 'N')
	{
		int choixMenu;
		printf("Taper \033[32m1\033[0m pour test uni test unitaire, \033[32m2\033[0m pour generer tous les donnees du TP : \n");
		scanf("%d", &choixMenu);
		fflush(stdin);

		/*Test unitaire*/
		if (choixMenu == 1)
		{
			int n = 0;
			printf("Taille tableau ? 500, 1000 ou 10 000 ?");
			scanf("%d", &n);

			int choixTab;
			printf("\nPour un test sur tableau ordonne taper 1, pour tableau non ordonne taper 2 : ");
			scanf("%d", &choixTab);

			int choixTri;
			affMenuTri();
			scanf("%d", &choixTri);

			if (choixTab == 1)
				mainTabTrie(tabTrie, n, tabFonction[choixTri], tabNomTri[choixTri], 1);

			else if (choixTab == 2)
			{
				int * tabTmp = copieTab(T, n);
				tabTmp[n];
				mainTabTrie(tabTmp, n, tabFonction[choixTri], tabNomTri[choixTri], 1);
				free(tabTmp);
			}
		}

		/*Génération tableau*/
		else if (choixMenu == 2)
		{
			mainTotal(T, tabTrie, tabFonction, tabClockTri, tabNomTri);
			affichageTabClok(tabClockTri, nbTri, tabNomTri);
		}

		do
		{
			printf("\n\nVoulez-vous recommencer ? (O/N)\n");
			scanf("%s", &recommencer[0]);
		} while (recommencer[0] != 'O' && recommencer[0] != 'N');
	}

	return EXIT_SUCCESS;
}

/*fonction de tri d'un tableau ordonné*/
float mainTabTrie(int T[], int n, void *tabFonction, char nomTri[], int nbIteration)
{

	printf("\n\n%s \n", nomTri);
	printf("\n\nTaille tableau : \033[31m%d\033[0m\n", n);

	float time = triTable(T, n, tabFonction, nomTri, nbIteration);

	return time;
}

void mainTotal(int T[], int tabTrie[], void(*tabFonction[])(), float tabClockTri[], char * tabNomTri[])
{
	int tabTaille[] = { 500, 1000, 10000 };


	int positionTabClock = 0;

	for (int itFonction = 0; itFonction < nbTri; itFonction++)
	{
		for (int itTailleTab = 0; itTailleTab < 3; itTailleTab++)
		{
			tabClockTri[positionTabClock] = mainTabTrie(tabTrie, tabTaille[itTailleTab], tabFonction[itFonction], tabNomTri[itFonction], 1);
			//tabClockTri[positionTabClock] = positionTabClock;
			positionTabClock++;
		}
		positionTabClock += 3;
	}

	positionTabClock = 3;

	for (int itFonction = 0; itFonction < nbTri; itFonction++)
	{
		for (int itTailleTab = 0; itTailleTab < 3; itTailleTab++)
		{
			int * tabCopie = copieTab(T, tabTaille[itTailleTab]);
			tabCopie[tabTaille[itTailleTab]];
			tabClockTri[positionTabClock] = mainTabTrie(tabCopie, tabTaille[itTailleTab], tabFonction[itFonction], tabNomTri[itFonction], 10);
			//tabClockTri[positionTabClock] = positionTabClock;
			positionTabClock++;
			free(tabCopie);
		}
		positionTabClock += 3;
	}

}

int verif(int T[], int n)
{
	for (int i = 0; i < n - 1; i++)
		if (T[i] > T[i + 1])
			return 1;

	return 0;

}
void generationTable(int T[], int n)
{
	srand(time(NULL));

	for (int i = 0; i < n; i++)
		T[i] = rand() % N;
}

int *copieTab(int T[], int n)
{
	int *tabTrie = malloc(n * sizeof(int));

	for (int j = 0; j < n; j++)
		tabTrie[j] = T[j];

	return tabTrie;
}

int *generationTableTriee(int T[], int n)
{
	int *tabTrie = copieTab(T, n);
	tabTrie[n];

	triParInsertion(tabTrie, n);

	return tabTrie;
}

