#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>


int main1()
{
	//printf("Hello World!\n");
	char a;
	do
	{
		printf("Tapez 1 pour quitter : \n");
		scanf("%c", &a);
	}
	while(a != '1');
	return 0;
}

int main2()
{
	int a, b;
	printf("Donnez une valeur entière pour a: ");
	scanf("%d", &a);
	printf("Donnez une valeur entière pour b: ");
	scanf("%d", &b);
	if ( b == 0) {
		printf("ERREUR : b doit être non nul.\n");
		return 0;
	}

	printf("a+b = %d+%d = %d\n",a, b, a+b);
	printf("a-b = %d-%d = %d\n",a, b, a-b);
	printf("a*b = %d*%d = %d\n",a, b, a*b);
	printf("a/b = %d/%d = %d\n",a, b, a/b);
	return 0;
}

int main()
{
	int a, b, i, res = 1;
	printf("Donnez une valeur entière pour a: ");
	scanf("%d", &a);
	printf("Donnez une valeur entière pour b: ");
	scanf("%d", &b);

	for (i=0; i < b; i++){
		res *= a;
	}
	printf("Le resultat de a^b = %d\n", res);

	return 0;
}
