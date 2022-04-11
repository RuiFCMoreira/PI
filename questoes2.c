#include <stdio.h>
#include <stdlib.h>

typedef struct lligada {
        int valor;
        struct lligada *prox;
} *LInt;

// 1
int length (LInt l){
    int count = 0;
    while (l){
        count++;
        l = l->prox;
    }
    return count;
}

// 2
void freeL (LInt l){
    LInt aux;
    while (l){
        aux = l;
        l = l->prox;
        free(aux);
    }
}

// 3
void imprimeL (LInt l) {
    while (l){
        printf("%d\n",l->valor);
        l = l->prox;
    }
}

// 4 ATENÇAO
 LInt reverseL (LInt l){
    LInt prox = l->prox;
    l->prox = NULL;
    while(prox) {
        LInt temp = prox->prox;
        prox->prox = l;
        l = prox;
        prox = temp;
    }
    return l;
 }

// 5
void insertOrd (LInt* l, int x) {
    LInt new = malloc(sizeof(struct lligada));
    new->valor = x;
    new->prox = NULL;
    LInt prev = NULL;
    while(*l && (*l)->valor < x){
        prev = (*l);
        l = &((*l)->prox);
    } 
    if(prev) {
        new->prox = (*l);
        prev->prox = new;
    }
    else {
        new->prox = (*l);
        *l = new;
    }
}

// 6
int removeOneOrd (LInt * l, int x){
    int r = 1;
    LInt prev = NULL;
    while (*l && (*l)->valor < x){
        prev = (*l);
        l = &((*l)->prox);
    }
    if(prev){
        if ((*l)->valor == x){
            LInt temp = (*l);
            (*l) = (*l)->prox;
            free(temp);
            r = 0;
            //prev->prox = ((*l)->prox);
            //(*l)->prox = NULL;
            //freeL(*l);
        }
    }
}

int removeOneOrd2(LInt* l, int x) {
    if((*l)->valor == x) {
        LInt temp = (*l);
        (*l) = (*l)->prox;
        free(temp);
        return 0;
    }
    LInt prev = (*l);
    while(prev->prox) {
        LInt list = prev->prox;
        if(list->valor == x) {
            prev->prox = list->prox;
            free(list);
            return 0;
        }
        prev = prev->prox;
    }
    return 1;
}

// 7
void merge (LInt *r, LInt a, LInt b){
    if (!a && !b) return;
    if (b == NULL || a != NULL && a->valor < b->valor){
        (*r) = a;
        merge(&((*r)->prox),a->prox,b);
    }
    else {
        (*r) = b;
        merge(&((*r)->prox),a,b->prox);
    }
}

// 8
void splitQS(LInt l, int x, LInt *mx, LInt *Mx) {
    if(!l) return;
    if(l->valor < x) {
        (*mx) = l;
        (*Mx) = NULL;
        splitQS(l->prox, x, &((*mx)->prox), Mx);
    }
    else {
        (*Mx) = l;
        (*mx) = NULL;
        splitQS(l->prox, x, mx, &((*Mx)->prox));
    }
}

// 9
LInt parteAmeio(LInt *l){
    int meio = length(*l)/2;
    if(meio == 0) return NULL;
    LInt y = (*l);
    LInt prev = NULL;
    for(int i = 0; i < meio; i++) {
        prev = (*l);
        (*l) = (*l)->prox;
    }
    prev->prox = NULL;
    return y;
}

// 10
int removeAll (LInt *l, int x){
    int count = 0;
    LInt prev = NULL;
    while (*l){
        if((*l)->valor == x) {
            if(!prev) (*l) = (*l)->prox;
            else prev->prox = (*l)->prox;
            rem++;
        }
        else {
            prev = (*l);
            l = &((*l)->prox);
        }
    return count;
}

// 11
int removeDups (LInt *l){
    int rem = 0;
    for(;*l; l = &((*l)->prox)) {
        LInt prevAux = (*l), aux = (*l)->prox;
        for(; aux; aux = prevAux->prox) {
            if(aux->valor == (*l)->valor) {
                prevAux->prox = aux->prox;
                rem++;
                free(aux);
            }
            else prevAux = aux;
        }
    }
    return rem;
}

// 12
int removeMaiorL(LInt *l) {
    int max = (*l)->valor;
    LInt prev = NULL;
    LInt maxPrev = NULL;
    LInt maxL = (*l);
    LInt list = (*l);
    for(;list; list = list->prox) {
        if(list->valor > max) {
            maxPrev = prev;
            maxL = list;
            max = list->valor;
        }
        prev = list;
    }
    if(!maxPrev) (*l) = (*l)->prox;
    else maxPrev->prox = maxL->prox;
    return max;
}

// 13
void init (LInt * l){
    LInt prev = NULL;
    while ((*l)->prox){
        prev = *l;
        l = &((*l)->prox);
    }
    if (!prev){
        free(*l);
        *l = NULL;
    }
    else {
        prev->prox = NULL;
        free(*l);
    }
}

// 14
void appendL (LInt *l , int x){
    LInt aux = malloc(sizeof(struct lligada));
    aux->valor = x;
    aux->prox = NULL;
    if(!(*l)) (*l) = aux;
    else {
        while ((*l)->prox){
            l = &((*l)->prox);
        }
        (*l)->prox = aux;
    }
}

// 15
void concatL (LInt *l, LInt aux){
    if(!(*l)) (*l) = aux;
    else {
        while ((*l)->prox){
            l = &((*l)->prox);
        }
        (*l)->prox = aux;
    }
}

// 16
LInt cloneL (LInt l){
    if (!l) return NULL;
    LInt aux = malloc(sizeof(struct lligada));
    aux->valor = l->valor;
    aux->prox = cloneL(l->prox);
    return aux;
}

// 17
LInt cloneRev (LInt l) {
    LInt list = NULL;
    while(l) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = l->valor;
        new->prox = list;
        list = new;
        l = l->prox;
    }
    return list;
} 

// 18
int maximo (LInt l){
    int max = 0;
    while (l){
        if (l->valor > max) max = l->valor;
        l = l->prox;
    }
    return max;
}

// 19
int take (int n, LInt *l){
    int i = 0;
    while (i<n && *l){
        i++;
        l = &((*l)->prox);
    }
    if(!(*l)) return i;
    for(;*l;) {
        LInt temp = (*l)->prox;
        free(*l);
        *l = temp;
    }
    return n;
}

// 20
int drop (int n, LInt *l){
    int i = 0;
    while (i<n && *l){
        i++;
        LInt temp = (*l)->prox;
        free(*l);
        *l = temp;
    }
    return i;
}

// 21
 LInt Nforward (LInt l, int N){
     int i;
     for(i=0; i<N; i++)
         l = l->prox;
     return l;
 }

 // 22
 int listToArray (LInt l, int v[], int N){
    int i;
    for (i = 0; i < N && l;i++){
        v[i] = l->valor;
        l = l->prox;
    }
    return i;
 }

 // 23
LInt arrayToList (int v[], int N){
    if (N==0) return NULL;
    LInt aux = malloc(sizeof(struct lligada));
    aux->valor = v[0];
    aux->prox = arrayToList(v+1,N-1);
    return aux;
}

// 24
LInt somasAcL (LInt l){
    int sum = 0;
    LInt list = NULL ,temp = NULL;
    while (l){
        sum += l->valor;
        LInt new = malloc(sizeof(struct lligada));
        new->valor = sum;
        new->prox = NULL;
        if (!list) list = temp = new;
        else temp = temp->prox = new;
        l = l->prox;
    } 
    return list;
}

// 25
void remreps (LInt l){
    if (l){
        while (l->prox){
            if (l->prox->valor == l->valor){
                LInt temp = l->prox;
                l->prox = temp->prox;
                free(temp);
            }
            else 
                l = l->prox;
        }
    }
}

// 26
LInt rotateL2 (LInt l) {
    if(!l || !(l->prox)) return l;
    LInt temp = l;
    LInt list = l->prox;
    while(temp->prox) temp = temp->prox; 
    l->prox = NULL;
    temp->prox = l;
    return list;
}

// 27
LInt parte(LInt l) {
    if(!l || !l->prox) return NULL;
    LInt newL = l->prox;
    l->prox = l->prox->prox;
    newL->prox = parte(l->prox);
    return newL;
}


// PARTE 2

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

// 28
int max (int a, int b){
    if (a>b)
        return a;
    else 
        return b;
}

int altura (Abin a){
    int r = 0;
    if (a)
        r = 1 + max(altura(a->esq),altura(a->dir));
    return r;
}

// 29
ABin cloneAB (ABin a){
    if (a == NULL) return NULL; 
    ABin new = malloc(sizeof(struct nodo));
    new->valor = a -> valor;
    new->esq = cloneAB(a->esq);
    new->dir = cloneAB(a->dir);
} 

// 30
void mirror(ABin * tree) {
    if((*tree)) {
        ABin temp = (*tree)->esq;
        (*tree)->esq = (*tree)->dir;
        (*tree)->dir = temp;
        mirror(&((*tree)->esq));
        mirror(&((*tree)->dir));
    }
}

// 31 
void inorderaux(ABin tree, LInt * list) {
    LInt aux;
    if(tree) {
        inorderaux(tree->dir,list);

        aux = malloc(sizeof(struct lligada));
        aux->valor = tree->valor;
        aux->prox = *list;

        *list = aux;

        inorderaux(tree->esq,list);
    }
}

void inorder (ABin tree, LInt * list) {
    *list = NULL;
    inorderaux(tree,list);
}

// 32 
void preorderaux(ABin tree,LInt * list){
    LInt aux;
    if(tree) {
        preorderaux(tree->dir,list);
        preorderaux(tree->esq,list);

        aux = malloc(sizeof(struct lligada));
        aux->valor = tree->valor;
        aux->prox = *list;

        *list = aux;
    }
}

void preorder (ABin tree, LInt * list){
    *list = NULL;
    preorderaux(tree,list);
}

// 33
void posorderaux(ABin tree,LInt * list){
    LInt aux;
    if(tree) {
        aux = malloc(sizeof(struct lligada));
        aux->valor = tree->valor;
        aux->prox = *list;

        *list = aux;

        preorderaux(tree->dir,list);
        preorderaux(tree->esq,list);
    }
}

void posorder (ABin tree, LInt * list){
    *list = NULL;
    posorderaux(tree,list);
}

// 34
int depth(ABin a, int x) {
    if(!a) return -1;

    if(a->valor == x) return 1;

    int esq = depth(a->esq,x);
    int dir = depth(a->dir,x);

    if(esq == -1 && dir == -1) return -1;
    if(esq == -1) return 1 + dir;
    if(dir == -1) return 1 + esq;
    return esq < dir ? 1 + esq : 1 + dir;
}

// 35
int freeAB (ABin a){
    if (a == NULL) return 0;
    else {
        free(a);
        return 1 + freeAB(a->esq) + freeAB(a->dir);
    }
}

// 36
int pruneAB (ABin *a, int l){
    if (!(*a)) return 0;
    int n;
    if(l == 0) {
        n = 1 + pruneAB(&((*a)->esq),0) + pruneAB(&((*a)->dir),0);
        free(*a);
        (*a) = NULL;
    }
    else n = pruneAB(&((*a)->esq),l - 1) + pruneAB(&((*a)->dir),l - 1);
    
    return n;
}

// 37
int iguaisAB (ABin a, ABin b) {
    if(!a && b || !b && a) return 0;
    if(!a && !b || a == b) return 1;
    return a->valor == b->valor && iguaisAB(a->esq,b->esq) && iguaisAB(a->dir,b->dir);
}

// 38
LInt concat(LInt a, LInt b) {
    if(!a) return b;
    LInt temp = a;
    while(temp->prox) temp = temp->prox;
    temp->prox = b;
    return a;
}
 
LInt nivelL (ABin a, int n) {
    if(!a || n < 1) return NULL;
    if(n == 1) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = a->valor;
        new->prox = NULL;
        return new;
    }
    else return concat(nivelL(a->esq,n - 1),nivelL(a->dir,n - 1));
} 

// 39
int nivelV (ABin a, int n, int v[]){
    if (!a || n < 1) return 0;
    if (n == 1){
        *v = a->valor;
        return 1;
    }
    else {
        int e = nivelV(a->esq,n - 1,v);
        int d = nivelV(a->dir,n - 1,v+e);
        return e + d;
    }
}

// 40
int dumpAbin (ABin a, int v[], int N){
    if (a && N > 0){
        int e = dumpABin (a->esq,v,N);
        if (e<N){
            v[e] = a->valor;
            return 1 + e + dumpAbin(a->dir,v+e+1,N-e-1);
        }
        else return N;
    }
    else return 0;
}

// 41
ABin somasAcA (ABin a){
    if (!a) return NULL;
    ABin aux = malloc(sizeof(struct nodo));
    aux->esq = somasAcA(a->esq);
    aux->dir = somasAcA(a->dir);
    aux->valor = a->valor + (aux->esq ? aux->esq->valor : 0) + (aux->dir ? aux->dir->valor : 0);
    return aux;
}

// 42
int contaFolhas (ABin a){
    if (!a) return 0;
    if (a->esq == NULL && a->dir == NULL) return 1;
    
    return contaFolhas(a->esq) + contaFolhas(a->dir);
}

// 43
ABin cloneMirror (ABin a){
    if (!a) return NULL;
    ABin new = malloc(sizeof(struct nodo));
    new->valor = a->valor;
    new->esq = cloneMirror(a->dir);
    new->dir = cloneMirror(a->esq);
    return new;
}

// 44
int addOrd (ABin *a, int x) {
    while(*a) {
        if((*a)->valor == x) return 1;
        if((*a)->valor > x) a = &((*a)->esq);
        else a = &((*a)->dir);
    }
    ABin new = malloc(sizeof(struct nodo));
    new->valor = x;
    new->esq = new->dir = NULL;
    (*a) = new;
    return 0;
}

// 45
int lookupAB (ABin a, int x){
    while(a) {
        if(a->valor == x) return 1;
        if(a->valor > x) a = a->esq;
        else a = a->dir;
    }
    return 0;
}

// 46
int depthOrd (ABin a, int x){
    int n = 1;
    while(a) {
        if(a->valor == x) return n;
        if(a->valor > x) {
            n++;
            a = a->esq;
        }
        else{
            n++;
            a = a->dir;
        } 
    }
    return -1;
}

// 47
int maiorAB (ABin a){
    while (a->dir)
        a = a->dir;
    return a->valor;
}

// 48
void removeMaiorA (ABin *a){
    ABin prev;
    while ((*a)->dir){
        prev = *a;
        a = &((*a)->dir);
    }    
    ABin temp = (*a);
    free(*a);
    (*a) = temp->esq;
}

// 49
int quantosMaiores (ABin a, int x){
    if (!a) return 0;
    if (a->valor <= x) return quantosMaiores(a->dir,x);
    else return 1 + quantosMaiores(a->esq,x) + quantosMaiores(a->dir,x);
}

// 50
void listToBTree (LInt l, ABin *a){
    if (!l) return ;
    ABin new = malloc(sizeof(struct nodo));
    int meio = length(l) / 2;
    LInt temp = l, prev = NULL;
    int i;
    for (i = 0; i<meio ;i++){
        prev = temp;
        temp = temp->prox;
    }
    new->valor = temp->valor;
    new->esq = new->dir = NULL;
    if(prev) prev->prox = NULL;
    
    if(l != temp) listToBTree(l,&(new->esq));
    if(temp->prox) listToBTree(temp->prox,&(new->dir));
    (*a) = new;
}

// 51
int deProcuraAux(ABin a, int x, int maior) {
    if(!a) return 1;
    if((maior && a->valor < x) || (!maior && a->valor > x)) return 0;
    return deProcuraAux(a->esq,x,maior) && deProcuraAux(a->dir,x,maior);
}

int deProcura (ABin a) {
    if(!a) return 1;
    int b = deProcuraAux(a->esq,a->valor, 0) && deProcura(a->esq);
    int c = deProcuraAux(a->dir,a->valor, 1) && deProcura(a->dir);
    return b && c;
}