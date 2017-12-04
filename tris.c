#include "protoFonction.h"

void triParInsertion(int T[], int n)
{

	int tamp = 0;

	for (int k = 1; k < n; k++)
	{
		int i = k;

		tamp = T[k];

		while (i > 0 && tamp < T[i - 1])
		{
			T[i] = T[i - 1];
			i--;
		}

		T[i] = tamp;

	}
}

void triParSelection(int T[], int n)
{
	int max, j;

	for (int k = n - 1; k >= 0; k--)
	{
		j = k;
		max = T[k];

		for (int i = 0; i <= k; i++)
		{
			if (max < T[i])
			{
				max = T[i];
				j = i;
			}

		}

		T[j] = T[k];
		T[k] = max;
	}
}

void triParEchange(int T[], int n)
{

	int fin_tri = 1;
	int k = n - 1;

	while (fin_tri == 1)
	{
		fin_tri = 0;
		for (int i = 0; i < k; i++)
		{
			if (T[i] > T[i + 1])
			{
				int tamp = T[i];
				T[i] = T[i + 1];
				T[i + 1] = tamp;
				fin_tri = 1;
			}

		}

		k--;


	}
}


void ShellSort(int T[], int n)
{

	int tamp = 0;
	int pas = n / 3 + 1;


	while (pas >= 1)
	{
		for (int k = pas; k < n; k += pas)
		{
			int i = k;

			tamp = T[k];

			while (i > 0 && tamp < T[i - pas])
			{
				T[i] = T[i - pas];
				i -= pas;
			}

			T[i] = tamp;
		}

		pas /= 2;
	}
}

void heapsort(int T[], int n)
{

	for (int i = (n / 2) - 1; i >= 0; i--)
		placer(i, n - 1, T);

	for (int d = n - 1; d >= 1; d--)
	{
		int temp = T[0];
		T[0] = T[d];
		T[d] = temp;
		placer(0, d - 1, T);
	}
}

void placer(int g, int d, int *T)
{
	int i, j, x, place_trouvee;

	x = T[g];
	i = g;
	j = 2 * g + 1;
	place_trouvee = 0;

	while ((j <= d) && !(place_trouvee))
	{
		if (j < d)
			if (T[j + 1] > T[j])
				j = j + 1;

		if (x >= T[j])
			place_trouvee = 1;

		else
		{
			T[i] = T[j];
			i = j;
			j = 2 * i + 1;
		}

	}

	T[i] = x;

}

void quickSort(int T[], int n)
{
	int  g = 0;
	int d = n - 1;

	triQS(T, g, d);
}

void initialisationQS (int T[], int * k1, int * k2, int pivot)
{

	while (*k1 <= *k2)
	{
		while (T[*k1] < pivot)
			(*k1)++;

		while (T[*k2] > pivot)
			(*k2)--;

		if (*k1 > *k2)
			break;

		int tmp = T[*k2];
		T[*k2] = T[*k1];
		T[*k1] = tmp;
		(*k1)++;
		(*k2)--;
		
	}
}

void triQS(int T[], int g, int d)
{
	int k1 = g;
	int k2 = d;
	int pivot = T[g + (d - g) / 2];
	
	initialisationQS (T, &k1, &k2, pivot);
	
	if (d > k1)
		triQS(T, k1, d);

	if (g < k2)
		triQS(T, g, k2);
}




