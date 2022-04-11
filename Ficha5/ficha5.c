#include <stdio.h>
#include <string.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

//EXERCICIO 1
int nota (Aluno a){
	float notaTeste = a.teste;
	float somaMT = 0;
	float notaMT = 0;
	for (int i=0; i < 6; i++)
		somaMT += a.miniT[i];
	notaMT = (somaMT * 20) / 12;
	if (notaTeste >= 8.0 && notaMT >= 8.0)
		return 0.3 * notaMT + 0.7 * notaTeste;
	else return 0;
}


//EXERCICIO 2
int procuraNum (int num, Aluno t[], int N){
	int i, r=-1;
	for (i = 0; i<N && num >= t[i].numero ; i++) {
		if (num == t[i].numero) {
			r=i;
			break;
		}
	}
	return r;
}

//EXERCICIO 3

void swapA (Aluno arr[],int i, int j){
	Aluno temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}



void ordenaPorNum (Aluno t [], int N){
	int i, j;
		for (i = 0; i < N; i++){
			for (j=0; j < (N - i - 1); j++){
				if (t[j].numero > t[j+1].numero)
					swapA (t,j,j+1);
			}
		}
}


//EXERCICIO 4
// FIXME FAZER!!!!!1




// EXERCICIO 5 
void imprimeTurma (int ind[], Aluno t[], int N){
	int i, j;
	for (i = 0; i<N ; i++) {
		printf ("Nº: %d , ",t[ind[i]].numero);

		printf("Nome: ");
		for (j=0; t[ind[i]].nome[j] != '\0';  j++)
			printf("%c", t[ind[i]].nome[j]);

		printf(" , Nota: %d", nota(t[ind[i]]));

		printf("\n");
	}
}



int main (){
	Aluno t[4] = {{4444, "André", {2,1,0,2,2,2}, 10.5}
	 			,{2222, "Joana", {2,2,2,1,0,0}, 14.5} 
	 			,{7777, "Maria", {2,2,2,2,2,1}, 18.5}
	 			,{3333, "Paulo", {0,0,2,2,2,1}, 8.7} } ;
	int ind[5] = {1,3,0,2};
	imprimeTurma(ind,t,4);
	
}












