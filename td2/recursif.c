#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int facto(int i){
	if ( i == 0) return 1;
	else  if ( i == 1) return 1;
	else return i*facto(i-1);
}

int main()
{
	int n;

	do{
		printf("Donnez une valeur n: ");
		scanf("%d", &n);
	}
	while(n < 0);
	printf("La valeur de n! = %d\n", facto(n));

	return 0;
}