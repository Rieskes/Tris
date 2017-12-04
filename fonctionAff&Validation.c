#include "protoFonction.h"

void triTable(int T[], int n, void(*tabFonction[])(), float tabClock[], char * tabNomTri[], int nbTri, int nbInteration)
{

	int *tabATrier;
	clock_t start_t, end_t;

	for (int i = 0; i < 6; i++)
	{
		float sumClocks = 0;
		printf("\033[36m%s : \033[0m\n", tabNomTri[i]);

		for (int k = 1; k <= nbInteration; k++)
			printf("▒");

		printf("\n\n");

		fflush(stdout);

		for (int j = 1; j <= nbInteration; j++)
		{
			tabATrier = malloc(n * sizeof(int));

			for (int j = 0; j < n; j++)
				tabATrier[j] = T[j];

			start_t = clock();
			tabFonction[i](tabATrier, n);
			end_t = clock();

			if (verif(tabATrier, n) != 0)
			{
				printf("Erreur de tri, vérifiez la fonction %s\n", tabNomTri[i]);
				exit(1);
			}
			;
			printf("\033[2A\033[%dG\033[37m█\033[0m\033[12G%.0lf %%", j, (float)j / nbInteration * 100);
			fflush(stdout);

			sumClocks += (float)(end_t - start_t) / CLOCKS_PER_SEC;
			free(tabATrier);

			tabClock[i] = sumClocks / j;
			printf("\nTime (%d/%d) : %lf s\n", j, nbInteration, tabClock[i]);
		}
		printf("\n");
	}


}


int verif(int T[], int n)
{
	for (int i = 0; i < n - 1; i++)
		if (T[i] > T[i + 1])
			return 1;

	return 0;

}

void slowerFaster(float tabClock[], char * tabNomTri[], int nbTri)
{
	float timeMin = tabClock[0];
	float timeMax = tabClock[0];
	int triSlower;
	int triFaster;

	for (int i = 0; i < nbTri; i++)
	{
		if (tabClock[i] <= timeMin)
		{
			timeMin = tabClock[i];
			triFaster = i;
		}

		if (tabClock[i] >= timeMax)
		{
			timeMax = tabClock[i];
			triSlower = i;
		}
	}

	printf("Plus lent : %s avec une moyenne de %lf s\nPlus rapide : %s avec une moyenne de %lf s\n", tabNomTri[triSlower], tabClock[triSlower], tabNomTri[triFaster], tabClock[triFaster]);
}


