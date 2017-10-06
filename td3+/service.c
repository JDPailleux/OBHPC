#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <math.h>

typedef struct service_t{
	int* donnee;
	int size; // Taille du vecteur donnee.
	char* name; // Nom du service.
	int (*func)(int*, int); // Pointeur sur une fonction de traitement
}service_t;

void afficherTableau(int* t, int n){
	int i;
	printf("Tableau: \n");
	for (i =0; i < n; i++)
			printf("%d ", t[i]);
	printf("\n");
}

void tri(int* tab, int n){ // Fonction de tri utilisé par la médiane.
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

int minimun(int* d, int n){ // Un vecteur d'entier en entrée.
	int min = *(d+0); // Initialisation de min.

	for (int i = 1; i < n; i++)
		if ( min > *(d+i)) min = *(d+i);
	
	return min;
}

int maximum(int* d, int n){ // Un vecteur d'entier en entrée.
	int max = d[0]; // Initialisation de min.
	for (int i = 1; i < n; i++)
		if ( max < d[i]) max = d[i];
	
	return max;
}

int moyenne(int* d, int n){ // Un vecteur d'entier en entrée.
	int avg = 0; // Initialisation de min.

	for (int i = 0; i < n; i++)
		avg += *(d+i);
	avg /= n;

	return avg;
}

int medianne(int* d, int n){ // Un vecteur d'entier en entrée.
	int med;
	tri(d, n); // Tri du tableau car on suppose les données non triées.

	if (n%2 != 0) med = d[n/2];
	else  med = (d[n/2] + d[n/2 - 1])/2;

	return med;
}

int nbDonnee(char* str){ // Nombre de données dans une chaine de caractère.
	char* tmp = NULL;
	int i = 0;
	tmp = strtok(str, "data:;");

	while(tmp != NULL){
		i += 1;
		tmp = strtok(NULL, "data:;");
	}
	return i;
}

void remplirDonnee(int* tab, char* str){
	char* tmp = NULL;
	int i = 0;
	tmp = strtok(str, "data:; \n");

	while(tmp != NULL){
		tab[i] = atoi(tmp);		
		tmp = strtok(NULL, "data:; \n");
		i++;
	}
}

int request(char* str){
	char* req = NULL;
	int i = 0;
	req = strtok(str, ":");
	req = strtok(NULL,"\n");

	if (strcmp(req, "avg") == 0) return 0;
	if (strcmp(req, "med") == 0) return 1;
	if (strcmp(req, "min") == 0) return 2;
	if (strcmp(req, "max") == 0) return 3; 

	return -1; // Cas erreur
}

void extraction(char* file){ // Fonction d'extraction d'information.
	FILE *fp;
	fp = fopen(file, "r");	// Ouverture du fichier en mode lecteur.
	if ( fp != NULL){
		char buf[518]; 		// Buffer
		int i;
		service_t s; 		// On déclare le service.


		printf("============================\n");
		while ( fgets( buf, sizeof(buf), fp ) != NULL ) /* read a line */
      		{
      			// Nom du service
      			s.name = buf; 
				// Data du service + taille du vecteur.
				fgets( buf, sizeof(buf), fp );
				char* new = malloc(518);
				strcpy(new, buf);
				s.size = nbDonnee(buf); 	// Size du vecteur;	
				s.donnee = malloc(sizeof(int)*s.size);
				remplirDonnee(s.donnee, new);
	
				//Request et affichage
				fgets( buf, sizeof(buf), fp );
				i = request(buf);
				afficherTableau(s.donnee, s.size);
				if(i ==  0) { s.func = moyenne; printf("Avg : %d\n", s.func(s.donnee, s.size)); }
				if(i ==  1) { s.func = medianne; printf("Med : %d\n", s.func(s.donnee, s.size)); }
				if(i ==  2) { s.func = minimun; printf("Min : %d\n", s.func(s.donnee, s.size)); }
				if(i ==  3) { s.func = maximum; printf("Max : %d\n", s.func(s.donnee, s.size)); }
				if(i == -1) {break;}

				//Affichage du resultat du service.
				printf("============================\n");
				free(new);
			}
      	fclose (fp);
   }
   else
   {
    	perror (file); /* why didn't the file open? */
   }
}

int main(int argc, char** argv)
{
	int tab[7] = {1,0,3,4,5,7,4};

	service_t s;
	s.donnee = tab;
	s.func = medianne;
	int res = s.func(tab, 7);
	
	//printf("Resultat : %d\n", res);
	extraction("test.tx");


	return 0;
}