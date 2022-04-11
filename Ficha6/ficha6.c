#include <stdio.h>
#include <stdlib.h>
#define Max 10

//EXERCICIO 1

typedef struct staticStack {
   int sp;
   int values [Max];
} STACK, *SStack;


// (a)

void SinitStack (SStack s) {
	s->sp = 0;
	// (*a).b == a->b
}


// (b)
int SisEmpty (SStack s){
	return (s->sp == 0);
}

// (c)
int Spush (SStack s, int x){
	int r = 0;
	if (s->sp == Max) r=1;
	else {
		s->values[s->sp] = x;
		s->sp ++;
	}
	return r;
}

// (d) 
int Spop (SStack s, int *x){
	int r = 0;
	if (SisEmpty(s)) r = 1;
	else {
		*x = s->values[s->sp-1];
		s->sp--;
	} 
	return r;
}

// (e) 
int Stop (SStack s, int *x){
	int r = 0;
	if (SisEmpty(s)) r = 1;
	else 
		*x = s->values[s->sp-1];
	return r;
}



// EXERCICIO 2
typedef struct staticQueue {
    int front;
    int length;
    int values [Max];
} QUEUE, *SQueue; 

// (a) 
void SinitQueue (SQueue q){
	q->front = 0;
	q->length = 0;
}

// (b)
int SisEmptyQ (SQueue q) {
	return (q->length == 0);
}

// (c) 
int Senqueue (SQueue q, int x){
	int r = 0;
	if (q->length == Max)
		r = 1;
	else {
		q->values[ (q->front + q->length) % Max] = x; 
		q->length++;
	}
	return r;
}

// (d) 
int Sdequeue (SQueue q, int *x){
	int r = 0;
	if (SisEmptyQ(q)) r = 1;
	else {
		*x = q->values[q->front];
		q->front = (q->front + 1) % Max;
		q->length--;
	}
	return r;
}

// (e) 
int Sfront (SQueue q, int *x){
	int r = 0;
	if (SisEmptyQ(q)) r = 1;
	else 
		*x = q->values[q->front];
	return r;
}

// EXERCICIO 3
typedef struct dinStack {
    int size; // guarda o tamanho do array values
    int sp;
    int *values;
} *DStack;

int dupStack (DStack s) {
	int r = 0, i;
	int *t = malloc (2*s->size*sizeof(int));

	if (t == NULL) r = 1;
	else {
		for (i=0; i<s->size; i++) 
			t[i] = s->values[i];
		free (s->values);
		s->values = t;
		s->size*=2;
	}
	return r;
}

void DinitStack (DStack s){
	s->size = 0;
	s->sp = 0;
	s->values = malloc(Max * sizeof(int));
	if (s->values == NULL)
		printf("não há espaço na memoria\n");
}

int DisEmpty (DStack s){
	return (s->size == 0);
}

int Dpush (DStack s, int x){
	int r = 0; 
	if (s-> sp == s-> size) r=dupStack(s);
	s->values[s->sp] = x;
	s->sp++;
	return r;
}

int Dpop (DStack s, int *x){
	int r = 0;
	if (DisEmpty(s)) r = 1;
	else {
		*x = s->values[s->sp-1];
		s->sp--;
	} 
	return r;
}


int Dtop (DStack s, int *x){
	int r = 0;
	if (DisEmpty(s)) r = 1;
	else 
		*x = s->values[s->sp-1];
	return r;
}

typedef struct dinQueue {
    int size; // guarda o tamanho do array values
    int front;
    int length;
    int *values;
} *DQueue;






int main (){
	return 0;
}