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

void dumpABin (ABin a,int N){
	if (a){
		dumpABin(a->esq,N);
		printf("%d ",a->valor);
		dumpABin(a->dir,N);
	}
}

void freeABin (ABin a){
	if (a){
		freeABin(a->esq);
		freeABin(a->dir);
		free(a);
	}
}

// Questão 1
// a)
ABin removeMenor (ABin *a){
    ABin r = NULL;
    while (*a && (*a)->esq) 
        a = &((*a)->esq);
    r = *a;
    *a = (*a)->dir;
    return r;
}

// b)
void removeRaiz (ABin *a){
    ABin aux;
    if(*a){
        aux = removeMenor(&(*a)->dir);
        if(aux){
            aux->esq = (*a)->esq;
            aux->dir = (*a)->dir;
            free(*a);
            *a = aux;
        }
        else{
            aux = *a;
            *a = (*a)->esq;
            free(aux);
        }
    }
}

// c)
int removeElem (ABin *a, int x){
    int r = -1;
    if(*a){
        if ((*a)->valor == x){
            removeRaiz(a);
            r = 0;
        }
        else if ((*a)->valor < x)
                r = removeElem(&((*a)->dir),x);
            else 
                r = removeElem(&((*a)->esq),x);
    }
    return r;
}

// Questão 2
void rodaEsquerda (ABin *a){
    ABin b = (*a)->dir;
    (*a)->dir = b->esq;
    b->esq = (*a);
    *a = b;
}

void rodaDireita (ABin *a){
    ABin b = (*a)->esq;
    (*a)->esq = b->dir;
    b->dir = *a;
    *a = b;
}

void promoveMenor (ABin *a){

}


void promoveMaior (ABin *a){
}
ABin removeMenorAlt (ABin *a){
    return NULL;
}

// Questão 3
int constroiEspinhaAux (ABin *a, ABin *ult){
    return (-1);
}
int constroiEspinha (ABin *a){
    ABin ult;
    return (constroiEspinhaAux (a,&ult));
}

ABin equilibraEspinha (ABin *a, int n) {
	return NULL;
}

void equilibra (ABin *a) {
}
