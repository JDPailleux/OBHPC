#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void remplirTableau(int* tab, int n){
	int i;
	srand(time(0));
	for(i =0; i < n; i++)
		tab[i] = rand()%100;
}

void afficherTableau(int* t, int n){
	int i;
	for (i =0; i < n; i++)
			printf("%d ", t[i]);
	printf("\n");
}

int min(int* tab, int n){
	int min = *(tab + n-1), i;
	for(i = 0; i < n-1; i++)
		if (min > *(tab+i)) min = *(tab+i);
	return min;
}

int max(int* tab, int n){
	int max = *(tab + n-1), i;
	for(i = 0; i < n-1; i++)
		if (max < *(tab+i)) max = *(tab+i);
	return max;
}

void tri(int* tab, int n){
	int i, j, tmp, i_min, v_min;
	for(i = 0; i < n; i++){
		i_min = i;
		v_min = *(tab+i);
		for(j = i+1; j < n; j++){
			if( *(tab+j) < *(tab+i_min)){
				i_min = j;
				v_min = *(tab+j);
			}
		}
		tmp = *(tab+i);
		*(tab+i) = *(tab+i_min);
		*(tab+i_min) = tmp;
	}
}

int main()
{
	int n;
	int* tab;

	printf("Veuillez rentrer un entier N: \n");
	scanf("%d",&n);
	tab = malloc(sizeof(int)*n);

	remplirTableau(tab,n);
	afficherTableau(tab,n);
	printf("Min = %d\n", min(tab,n));
	printf("Max = %d\n", max(tab,n));
	tri(tab,n);
	afficherTableau(tab,n);
	free(tab);

	return 0;
}