#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void afficherTableau(int* t, int n){
	int i;
	for (i =0; i < n; i++)
			printf("%d ", t[i]);

}

int sommeTableau(int* t, int n){
	int i, res = 0;
	for (i =0; i < n; i++)
			res += t[i];
	return res;
}

float moyenneTableau(int* t, int n){
	int i, res = 0;
	for (i =0; i < n; i++)
			res += t[i];
	return (float)res/n;
}

int main()
{
	int tab[20];
	int i;
	for (i= 0; i < 20; i++) 
		tab[i] = 2*i+1;
	afficherTableau(tab,20);
	printf("Somme tableau = %d\n", sommeTableau(tab, 20));
	printf("Moyenne tableau = %d\n", moyenneTableau(tab, 20));

	return 0;
}