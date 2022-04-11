#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char *palavra;
	int ocorr;
    struct celula * prox;
} * Palavras;

//Exercicio 1
void libertaLista (Palavras l){
	Palavras aux;
	while (l != NULL){
		aux = l;
		l = l->prox;
		free(aux);
	}
}

void libertaLista2 (Palavras l){
	if (l != NULL){
		libertaLista2(l->prox);
		free(l);
	}
}

//Exercicio 2
int quantasP (Palavras l){
	int res = 0;
	while (l!=NULL){
		res++;
		l = l->prox;
	}
	return res;
}

int quantasP2 (Palavras l){
	if (l==NULL) 
		return 0;
	else 
		return 1+quantasP2(l->prox);
}

//Exercicio 3
void listaPal (Palavras l) {
	while(l!=NULL){
		printf("%s\n",l->palavra);
		l=l->prox;
	}
}

//Exercicio 4
char * ultima (Palavras l) {
	if (l==NULL) return NULL;
	//if (l->prox == NULL) return l->palavra;
	while (l->prox!=NULL){
		l = l->prox;
	}
	return l->palavra;

	/* stor :
	while (l && l->prox) l = l->prox;
	//return l ? l->palavra : NULL;
	if (l) return l->palavra
	else return NULL
	*/ 
}

//Exercicio 5
Palavras acrescentaInicio (Palavras l, char *p) {
	Palavras aux = malloc(sizeof(struct celula));
	aux->palavra = strdup(p);
	aux->ocorr = 1;
	aux->prox = l;
	return aux;
}

//Exercicio 6
Palavras acrescentaFim (Palavras l, char *p){
	/*Palavras inicio = l;
	Palavras aux = malloc(sizeof(struct celula));
	aux->palavra = strdup(p);
	aux->ocorr = 1;
	aux->prox = NULL;
	while (l->prox!=NULL)
		l = l->prox;
	if (l!=NULL) {
		l->prox = aux;
		return inicio;
	}
	else return aux;*/


	//stor
	Palavras aux2 = l, aux = malloc(sizeof(struct celula));
	aux->palavra = strdup(p);
	aux->ocorr = 1;
	aux->prox = NULL;

	while(l && l->prox) l = l->prox;
	if (l){
		l->prox = aux;
		return aux2;
	} 
	else return aux;
}


//Exercicio 7
Palavras acrescenta (Palavras l, char *p) {
	if (l==NULL){
		return acrescentaInicio(l,p);
	}
	else if (strcmp(p,l->palavra) < 0)
			return acrescentaInicio(l,p);
		 else if (strcmp(p,l->palavra) == 0){
				l->ocorr++;
				return l;
			  } else {
			  		l->prox = acrescenta(l->prox,p);
			  		return l;
			}
}

//Exercicio 8
Palavras maisFreq (Palavras l) {
	Palavras aux ;
	int n = 0;
	while (l && l->prox){
		if (l->ocorr > n){
			aux = l;
			n = l->ocorr;
		}
		l = l->prox;
	}
	return aux;
}

int main () {
    Palavras dic = NULL;

    char * canto1 [44] = {"as", "armas", "e", "os", "baroes", "assinalados",
                          "que", "da", "ocidental", "praia", "lusitana", 
                          "por", "mares", "nunca", "de", "antes", "navegados",
                          "passaram", "ainda", "alem", "da", "taprobana",
                          "em", "perigos", "e", "guerras", "esforcados",
                          "mais", "do", "que", "prometia", "a", "forca", "humana",
                          "e", "entre", "gente", "remota", "edificaram", 
                          "novo", "reino", "que", "tanto", "sublimaram"};

    printf ("\n_____________ Testes _____________\n\n");

    int i; struct celula *p;
    for (i=0;i<44;i++)
        dic = acrescentaFim (dic, canto1[i]);

    printf ("Foram inseridas %d palavras\n", quantasP (dic));
    printf ("palavras existentes:\n");
    listaPal (dic);
    printf ("última palavra inserida: %s\n", ultima (dic));

    libertaLista (dic);

    dic = NULL;

    srand(42);
    
    for (i=0; i<1000; i++)
        dic = acrescenta (dic, canto1 [rand() % 44]);
    
    printf ("Foram inseridas %d palavras\n", quantasP (dic));
    printf ("palavras existentes:\n");
    listaPal (dic);
    printf ("última palavra inserida: %s\n", ultima (dic));
    
    p = maisFreq (dic);
    printf ("Palavra mais frequente: %s (%d)\n", p->palavra, p->ocorr);
    
    printf ("\n_________ Fim dos testes _________\n\n");

    return 0;
}



