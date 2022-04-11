#include <stdio.h>

/* EXERCICIO 1
A)  1 1 4           B) OUT : 13
	2 2 5
	3 3 6
	4 4 7
OUT:5 5 8
*/

//EXERCICIO 2 
void swapM (int *x, int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp; 
}

//EXERCICIO 3
void swap (int v[],int i,int j){
	int tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;

	//v[i] += v[j];
	//v[j] = v[i] - v[j];
	//v[i] -= v[j];

	//swapM(v+i,v+j);
}

//EXERCICIO 4
int soma (int v[],int N){
	int i = 0, soma = 0;
	while (i<N){
		soma += v[i];
		i++;
	}
	return soma;
}

//EXERCICIO 5
//com a swapM
void inverteArrayM (int v[],int N){
	int i,j;
	i = 0; j = N-1;
	while (i<j){
		swapM(v+i,v+j);
		i++;
		j--;
		
	}
}

//com a swap
void inverteArray (int v[],int N){
	int i,j;
	i = 0; j = N-1;
	while (i<j){
		swap(v,i,j);
		i++;
		j--;
	}
}


//EXERCICIO 6
int maximum (int v[],int N,int *m){
	if (N<=0) return -1;

	*m = v[0];
	int i=1;
	while (i<N){
		if (v[i]>*m) *m = v[i];
		i++;
	}
	return 0;
}

//EXERCICIOS 7 
void quadrados (int q[],int N){
	int i=0;
	q[i] = 0;
	while (i<N){
		q[i+1]= q[i] + (2 * i + 1);
		i++;
	}
}

//EXERCICIO 8
void aux (int v[],int N){
	if (N==1){
		v[0]= 1;
		return;
	}

	v[N-1] = 1;
	int i;
	for (i=N-2;i>0;i--){
		v[i] = v[i] + v[i-1];
	}
	v[0]=1;

}


void pascal (int v[],int N){
	if (N <= 0) return;

	if (N==1){
		v[0]= 1;
		return;
	}

	for (int i=1;i<=N;i++){
		aux(v,i);
		for (int b=0; b<i;b++)
    		printf("%d ", v[b] );
    	printf("\n");

	}
}

int main (){
	int x[5] = {1,2,8,4,5};
	int q[5] = {-1,-1,-1,-1,-1};
    /*swap (x,1,3);
    printf ("%d %d\n", x[1],x[3]);
    inverteArrayM(x,5);
    for (int i=0; i<5;i++)
    	printf("%d \n", x[i] );
	int m =0;
	maximum(x,5,&m);
	printf("%d\n",m );
	quadrados (q,5);*/
	pascal (q,5);
    return 0;
}