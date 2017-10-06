#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int taille(char* str){
	int i = 0, res = 0;
	while ( i < 128 && str[i] != '\0'){ 
		i++;
	}
	return i;
}

void inverse(char* str){
	int i = 0, tmp, t = taille(str);
	for( i = 0; i < t/2; i++){
		tmp = str[i];
		str[i] = str[t-i-1];
		str[t-i-1] = tmp;
	}
}

int main()
{
	char str[128];
	printf("Taper une chaine de caractères (inf à 128 lettres): \n");
	scanf("%s", str);
	printf("%s\n",str);
	printf("La taille est de : %d\n", taille(str));
	inverse(str);
	printf("L'inverse est : %s\n", str);


	return 0;
}