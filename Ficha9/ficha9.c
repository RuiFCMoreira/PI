#include <stdio.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;

ABin newABin (int r, ABin e, ABin d) {
   	ABin a = malloc (sizeof(struct nodo));
   	if (a!=NULL) {
      	a->valor = r; 
      	a->esq = e; 
      	a->dir = d;
   	}
	return a; 
}

//EXERCICIO 1  
// a)
int altura (ABin a){
	int r = 0;
	if (a == NULL) r = 0;
	else  if (altura(a->esq) > altura(a->dir))
				r = 1 + altura(a->esq);
		  else 
				r = 1 + altura(a->dir);
	return r;
}

// b) 
int nFolhas (ABin a){
	if (a->esq == NULL && a->dir == NULL)
		return 1;
	else 
		return (nFolhas(a->esq) + nFolhas(a->dir));
}

// c)
ABin maisEsquerda (ABin a){
	ABin res;
	while (a->esq)
		res = a->esq;
	return res;
}

// d)
void imprimeNivel (ABin a, int l){
	if (l = 0 && a)
		printf("%d ",a->valor);
	else 
		imprimeNivel(a->esq,l-1);
		imprimeNivel(a->dir,l-1);
}

// e) 
int procuraE (ABin a, int x){
	if (a) return 0;
	if (a->valor == x)
		return 1;
	else 
		return (procuraE(a->esq,x) == 1 || procuraE(a->dir,x) == 1);
}
