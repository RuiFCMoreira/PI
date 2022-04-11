#include "abin.h"

ABin newABin (int r, ABin e, ABin d) {
   ABin a = malloc (sizeof(struct nodo));
   if (a!=NULL) {
      a->valor = r; a->esq = e; a->dir = d;
   }
   return a;
}

ABin RandArvFromArray (int v[], int N) {
   ABin a = NULL;
    int m;
    if (N > 0){
    	m = rand() % N;
    	a = newABin (v[m], RandArvFromArray (v,m), RandArvFromArray (v+m+1,N-m-1));
    }
    return a;	
}

//EXERCICIO 1  
// a)
int myAltura (ABin a){
	int r = 0;
	if (a == NULL) r = 0;
	else  if (altura(a->esq) > altura(a->dir))
				r = 1 + altura(a->esq);
		  else 
				r = 1 + altura(a->dir);
	return r;
}

int max(int a, int b){
	return a>b ? a : b;
}

int altura (ABin a){
	int r = 0;
	if (a)
		r = 1 + max(altura(a->esq) , altura(a->dir));
	return r;
}

// b) 
int nFolhas (ABin a){
	int r = 0;
	if (a){
		if (a->esq == NULL && a->dir == NULL)
			r = 1;
		else 
			r = (nFolhas(a->esq) + nFolhas(a->dir));
	}
	return r;

}

// c)
ABin maisEsquerda (ABin a){
	while (a && a->esq)
		a = a->esq;
	return a;
}

// d)
void imprimeNivel (ABin a, int l){
	if (a){
		if (l == 0)
			printf("%d ",a->valor);
		else 
			imprimeNivel(a->esq,l-1);
			imprimeNivel(a->dir,l-1);
	}
	
}



/*
					23
			15				34
		6 		18 		29 		45
			  16		  31




inorder: 6 15 16 18 23 29 31 34 45
posorder: 6 16 18 15 31 29 45 34 23
preorder: 23 15 6 18 16 34 29 31 45
*/
void freeABin (ABin a){
	if (a){
		freeABin(a->esq);
		freeABin(a->dir);
		free(a);
	}
}

void dumpABin (ABin a,int N){
	if (a){
		dumpABin(a->esq,N);
		printf("%d ",a->valor);
		dumpABin(a->dir,N);
	}
}


void inorder (ABin a){
	if (a){
		inorder(a->esq);
		printf("%d ",a->valor);
		inorder(a->dir);
	}
}

void posorder (ABin a){
	if (a){
		posorder(a->esq);
		posorder(a->dir);
		printf("%d ",a->valor);
	}
}

void preorder (ABin a){
	if (a){
		printf("%d ",a->valor);
		preorder(a->esq);
		preorder(a->dir);
	}
}

// e)
int procuraE (ABin a, int x){
	int r = 0;
	if (a){
		r = (a->valor == x) || (procuraE(a->esq,x) == 1) || (procuraE(a->dir,x) == 1);
	}
	return r;
}



// f)
ABin procura (ABin a, int x){
	ABin r = NULL;
	if (a){
		if (a->valor == x)
			r = a;
		else if (a->valor > x)
				r = procura(a->esq,x);
			 else 
			 	r = procura(a->dir,x);
	}
	return r; 
}

// g)
int nivel (ABin a, int x){
	int r = -1;
	if (a){
		if (a->valor == x)
			r = 0;
		else if (a->valor > x)
				r = 1 + nivel(a->esq,x);
			 else 
			 	r = 1 + nivel(a->dir,x);
	}
	return r;
}

// h)
void imprimeAte (ABin a, int x){
	if (a){
		if (a)
	}
}





// MINITESTE 6
// ex1 
#include "miniteste.h"
#include <stdlib.h>

LInt procura(LInt l) {
    LInt aux = l;
    int i = 0;
    while (l!=NULL && i<10){
        i++;
        l = l->prox;
    }
    while (l!=NULL){
        aux = aux->prox;
        l = l->prox;
    }
    return aux;
}

// ex2
#include "miniteste.h"
#include <stdlib.h>

ABin newABin (int r, ABin e, ABin d) {
   ABin a = malloc (sizeof(struct nodo));
   if (a!=NULL) {
      a->valor = r; a->esq = e; a->dir = d;
   }
   return a;
}

ABin newABinTam (int tam,int r) {
    ABin a = malloc (sizeof(struct nodo));
    if (tam == 1){
        //ABin a = malloc (sizeof(struct nodo));
        if (a!=NULL) {
            a->valor = r; a->esq = NULL; a->dir = NULL;
        }  
    }
    else {
        tam--;
        //ABin a = malloc (sizeof(struct nodo));
        if (a!=NULL) {
            a->valor = r; a->esq = newABinTam(tam/2,r+1); a->dir = newABinTam(tam/2,r+2);
        } 
    }
    
   return a;
}

ABin cria() {
   return newABinTam(43,1);
}


