#include "protoFonction.h"

float triTable(int T[], int n, void *(tabFonction)(), char nomTri[], int nbIteration)
{
	clock_t start_t, end_t;

	float sumClocks = 0;
	float moyenneTemps = 0;

	printf("\n");
	for (int k = 1; k <= nbIteration; k++)
		printf("▒");

	printf("\n\n");

	fflush(stdout);

	for (int j = 1; j <= nbIteration; j++)
	{

		start_t = clock();
		(*tabFonction)(T, n);
		end_t = clock();

		if (verif(T, n) != 0)
		{
			printf("Erreur de tri, vérifiez la fonction %s\n", nomTri);
			exit(1);
		}

		printf("\033[2A\033[%dG\033[37m█\033[0m\033[12G%.0lf %%", j, (float)j / nbIteration * 100);
		fflush(stdout);

		sumClocks += (float)(end_t - start_t) / CLOCKS_PER_SEC;
		moyenneTemps = sumClocks / j;
		printf("\nTime (%d/%d) : %lf s\n", j, nbIteration, moyenneTemps);
	}

	printf("\n");

	return moyenneTemps;
}

void affichageTabClok(float tabClockTri[], int nbTri, char *tabNomTri[])
{
	tabClockTri[42];
	int positionTabClock = 0;


	printf("\n\nTableau genere : \n\n");

	printf("\t\t\t Tableaux deja tries   \t    Tableaux aleatoirement \n\t\t\t\t\t\t\tdesodronnes\n");
	printf("\t\t\t  500 \t   1 000    10 000    500    1 000    10 000\n");

	for (int i = 0; i < nbTri; i++)
	{
		printf("%s \t", tabNomTri[i]);

		for (int j = 0; j < 6; j++) {
			printf("%f ", tabClockTri[positionTabClock]);
			positionTabClock++;
		}
		printf("\n");
	}
}

void affNomtTriTab(int numTri)
{
	switch (numTri)
	{
	case 0:
		printf("Tri par Insertion ");
		break;
	case 1:
		printf("Tri Par Selection");
		break;
	case 2:
		printf("Tri Par Echange");
		break;
	case 3:
		printf("ShakeSort");
		break;
	case 4:
		printf("ShellSort");
			break;
	case 5:
		printf("Heapsort");
		break;
	case 6:
		printf("QuickSort");
		break;
	default :
		break;
	}
}

void affMenuTri()
{
	printf("0 : Tri par Insertion \n 1 : Tri Par Selection \n 2 : Tri Par Echange \n 3 : ShakeSort \n 4 : ShellSort \n 5 : Heapsort \n 6 : QuickSort \n\n");
}

void slowerFaster(float tabClock[], char * tabNomTri[], int nbTri, int positionTabClock)
{
	float timeMin = tabClock[positionTabClock - nbTri];
	float timeMax = tabClock[positionTabClock - nbTri];
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


