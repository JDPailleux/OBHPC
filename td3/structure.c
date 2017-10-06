#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct temps {
	int heures;
	int minutes;
	int secondes;
} temps;

void afficheTemps(temps t){
	printf("%dh %02dm %02ds\n",t.heures, t.minutes, t.secondes);
}

temps sommeTemps(temps t1, temps t2){
	t1.heures  = (t1.heures + t2.heures)%24 + (t1.minutes + t2.minutes)/60;
	t1.minutes = (t1.minutes + t2.minutes)%60 + (t1.secondes + t2.secondes)/60;
	t1.secondes = (t1.secondes + t2.secondes)%60;
	return t1;
}

int main()
{
	temps t1, t2, t3;
	t1.heures = 4; t1.minutes = 36; t1.secondes = 17;
	t2.heures = 19; t2.minutes = 53; t2.secondes = 9;
	t3.heures = 12; t3.minutes = 5; t3.secondes = 34;

	printf("t1 :"); afficheTemps(t1);
	printf("t2 :"); afficheTemps(t2);
	printf("t3 :"); afficheTemps(t3);
	printf("t1+t2 :"); afficheTemps(sommeTemps(t1,t2));
	printf("t1+t3 :"); afficheTemps(sommeTemps(t1,t3));
	printf("t2+t3 :"); afficheTemps(sommeTemps(t2,t3));

	return 0;
}