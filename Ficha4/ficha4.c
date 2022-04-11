#include <stdio.h>
#include <string.h>

//EXERCICIO 1
int isVogal (char c){
	char vogais[10] = "aeiouAEIOU";
	int i = 0;
	while (vogais[i] != '\0'){
		if (c == vogais[i]) return 1;
		i++;
	}
	return 0;
}

int contaVogais (char *s){
	int count ;
	count = 0;
	while (*s != '\0'){
		if (isVogal (*s) == 1) count++;
		s++;
	}
	return count;

}

/*int main() {
	char string[20] = "ola Mundo!";
	int r = contaVogais (string);
	printf("%d \n",r );		}*/

// EXERCICIO 2
void shiftEsq (char *s){
	int i = 0;
	while (s[i+1] != '\0'){
		s[i] = s[i+1];
		i++;
	}
	s[i] = '\0';
}

int retiraVogaisRepAux (char *s) {
	char aux[100];
	int i = 0, j = 0, removidos = 0;
	while (s[i] != '\0'){
		if (isVogal (s[i]) == 0) {
			aux[j] = s[i];
			j++;
		}
		else {
			if (s[i] == s[i-1]){
				removidos++;
			}
			else {
				aux[j] = s[i];
				j++;
			}
		}
		i++;
	}
	return removidos;
}

int retiraVogaisRep (char *s) {
	int i = 0, removidos = 0;
	while (s[i] != '\0'){
		if (isVogal (s[i]) == 1) {
			if (s[i] == s[i-1]){
				removidos++;
				shiftEsq (&s[i]);
				i--;
			}
		}
		i++;
	}
	return removidos;}


/*int main(){
	char string[] = "Estaa e umaa string coom duuuplicadoos";
	int r = retiraVogaisRep(string);
	int i=0;
	while (string[i]!='\0'){
		printf("%c",string[i]);		
		i++;
	}
	printf ("\nremovidos: %d", r);}*/

// EXERCICIO 3
int duplicaVogaisAux (char *s){
	char aux[100];
	int i = 0, j = 0, acrescentados = 0;
	while (s[i] != '\0'){
		if (isVogal (s[i]) == 0) {
			aux[j] = s[i];
			j++;
		}
		else {
			acrescentados++;
			aux[j] = s[i];
			aux[j+1] = s[i];
			j += 2;
		}
		i++;
	}
	i=0;
	while (aux[i]!='\0'){
		printf("%c",aux[i]);		
		i++;
	}
	return acrescentados;}

void shiftDir (char *s,char c){
	int i = 0;
	while (s[i] != '\0'){
		i++;
	}
	while (i > 0) {
		s[i] = s[i-1];
		i--;
	}
	s[i] = c;	}

int duplicaVogais (char *s){
	int i = 0, acrescentados = 0;
	while (s[i] != '\0'){
		if (isVogal (s[i]) == 1) {
			acrescentados++;
			shiftDir(s+i,s[i]);
		}
		i++;
	}
	return acrescentados;}


/*int main(){
	char string[200] = "Esta e uma string com duplicados\0";
	duplicaVogais(string);			
	int i=0;
	while (string[i]!='\0'){
		printf("%c",string[i]);		
		i++;
	}
	//printf ("\t acrescentados: %d \n", r);}		*/


//ARRAYS ORDENADOS
// EXERCICIO 1
int ordenado (int v[], int N){
	int i = 1;
	while (i<N){
		if (v[i] < v[i-1]) return 0;
		i++;
	}
	return 1;
}

/*int main(){
	int arr[5] = {1,2,1,4,5};
	int r = ordenado(arr,5);
	printf("%d\n",r ); }*/ 

// EXERCICIO 2
 void merge (int a[], int na, int b[], int nb, int r[]) {
 	int ia = 0, ib = 0, i = 0;
 	while (ia < na && ib < nb){
 			if (a[ia] < b[ib]) {
				r[i] = a[ia];
 				ia++;
 				i++;
 			}
 			else {
 				r[i] = b[ib];
 				ib++;
 				i++;
 			} 
	}

	while (ia < na){
		r[i] = a[ia];
		ia++;
		i++;
	}

	while (ib < nb){
		r[i] = b[ib];
		ib++;
		i++;
	}	
 }

 void mergeStor (int a[], int na, int b[], int nb, int r[]) {
 	int ia = 0, ib = 0, ir = 0;
 	for (ir = 0; ir < na+nb; ir++){
 		if (ia == na){
 			r[ir] = b[ib];
 			ib++;
 		}
 		else if (ib == nb){
 				r[ir] = a[ia];
 				ia++;
 			}
 			else if (a[ia] <= b[ib]){
 				r[ir] = a[ia];
 				ia++
 			}
 				else{
 					r[ir] = b[ib];
 					ib++,
 				}
 			}
	
 }


 // EXERCICIO 3

void swap (int v[],int i,int j){
	int temp = v[i];
	v[i] = v[j];
	v[j] = v[i];
}

 int partition (int v[], int N, int x){
 	int r, i;
 	r = i = 0;
 	while (i < N-1){
 		if (v[i] > v[N-1]) i++;
 		else {
 			swap (v,r,i);
 			r++;
 			i++; 	
 		}
 	}
 		swap(v,r,N-1);
 		return r;
}

 int partitionStor (int v[], int N, int x){
 	int r = 0; i = 0;
 	for(i=0; i+r<N ;i++){
 		if (v[i] > x){
 			swap(v,i,N-r-1);
 			r++; 
 			i--;
 		}
 	}
 	return N-r; 
 }
