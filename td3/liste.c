#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

struct element {
	char valeur;
	struct element* suivant;
};
typedef struct element Element;
typedef Element* Liste;

Liste ajoutElement(Liste l, char v ){
	if ( l == NULL){
		Element* e = malloc(sizeof(Element));
		e->valeur = v;
		e->suivant = NULL;
		l = e;
	}
	else{
		l->suivant = ajoutElement(l->suivant, v);
	}
	return l;
}

Liste enleveElement(Liste l, char v){
	if ( l != NULL){
		if (l->valeur == v){
			Liste tmp = l;
			l = l->suivant;
			free(tmp);
			return l;	
		}
		else{
			l->suivant = enleveElement(l->suivant, v);
		}
	}
	return l;
}

void afficheChaine(Liste l){
	Liste tmp = l;
	while(tmp != NULL){
		printf("%c -> ",tmp->valeur);
		tmp = tmp->suivant;
	}
	printf("NULL\n");
}


int main()
{
	Liste l = NULL;
	l = ajoutElement(l,'s');
	l = ajoutElement(l,'a');
	l = ajoutElement(l,'l');
	l = ajoutElement(l,'u');
	l = ajoutElement(l,'t');
	afficheChaine(l);
	l = enleveElement(l,'l');
	afficheChaine(l);
	l = ajoutElement(l,'u');
	l = ajoutElement(l,'t');
	afficheChaine(l);
	l = enleveElement(l,'t');
	afficheChaine(l);
	l = enleveElement(l,'s');
	afficheChaine(l);
	return 0;
}