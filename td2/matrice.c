#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void sommeMatricielle(int l, int c, int(*a)[c], int(*b)[c]){
	int i, j;
	for (i = 0; i < c; i++){
		for( j = 0; j < l; j++){
			a[i][j] += b[i][j];
		}
	}
}

void afficheMatrice(int l, int c, int(*a)[c] ){
	int i, j;
	for (i = 0; i < c; i++){
		printf("[");
		for( j = 0; j < l; j++){
			printf("%d ", a[i][j]);
		}
		printf("]\n");
	}
}

int main()
{
	int a[5][5], b[5][5], i, j;
	for (i = 0; i < 5; i++){
		for( j = 0; j < 5; j++){
			a[i][j] = i - 2*j;
			b[i][j] = -2*i + j;
		}
	}
	sommeMatricielle(5,5,a,b);
	afficheMatrice(5, 5, a);

	return 0;
}