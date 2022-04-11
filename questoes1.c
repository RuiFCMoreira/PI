#include <stdio.h>
#include <stdlib.h>

void exercicio1(){
	int maior = 0;
	int num ;
	printf("Maior de uma sequência\n");
	printf("Insere uma lista de números (um por linha) terminada em 0:\n");
	while (scanf("%d",&num) == 1){
		if (num == 0) break;
		if (num > maior) maior = num;
	}
	printf("Maior: %d \n",maior);
}

void exercicio2(){
	int somaTotal = 0, nElem = 0, num;
	printf("Media de uma sequência\n");
	printf("Insere uma lista de números (um por linha) terminada em 0:\n");
	while (scanf("%d",&num) == 1){
		if (num == 0) break;
		somaTotal += num;
		nElem++;
	}
	printf("Media: %f \n",(float) somaTotal/(float) nElem);
}

void exercicio3(){
	int maior = 0,secondMaior = 0;
	int num ;
	printf("Segundo maior de uma sequência\n");
	printf("Insere uma lista de números (um por linha) terminada em 0:\n");
	while (scanf("%d",&num) == 1){
		if (num == 0) break;
		if (num > maior){
			secondMaior = maior;
			maior = num;
		} 
		else if (num > secondMaior)
			secondMaior = num;
	}
	printf("2º Maior: %d \n",secondMaior);
}

int bitsUm (unsigned int n){
	int res = 0;
	while (n){
		res += (n%2);
		n >>= 1; // Shifts the bits in `n` one bit to the right, i.e., n = n / 2
	}
	return res;
}

int trailingZ (unsigned int n){
	int res = 0;
	while(n){
		if (n % 2 == 0) res++;
		n >>= 1;
	}
	return res;
}

int qDig (unsigned int n){
	if(n / 10 < 1) return 1;
	int res = 0;
	while (n){
		res++;
		n = n/10;
	}
	return res;
}

char * mystrcat (char s1[], char s2[]){
	char * cat = s1;
	int i = 0, j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0'){
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return cat;
}

char * mystrcpy (char *dest, char source[]){
	char * cpy = dest;
	while (*source){
		*dest = *source;
		dest++;
		source++;
	}
	*dest = '\0';
	return cpy;
}

int mystrcmp (char s1[], char s2[]){
	while (*s1 == *s2 && *s1){
		s1++;
		s2++;
	}
	return *s1 - *s2;
}


char * mystrstr (char s1[], char s2[]){
	int contem = 1;
	char * res = s1;
	char * iniS2 = s2;
	while(*s1 && *s2){
		if (*s1 != *s2){
			contem = 0;
			s2 = iniS2;
		}
		if (*s1 == *s2){
			if(!contem){
				contem = 1;
				res = s1;
			}
			s2++;
		}
		s1++;
	}
	if (contem && !(*s2)) return res;
	else return NULL;
}

void strrev(char s[]){
	int length = 0;
	while (s[length]!='\0')
		length++;
	char rev[length];
	for (int i = 0; i < length; i++) rev[i] = s[length-1-i];
	for (int i = 0; i < length; i++) s[i] = rev[i];
}

int isVogal (char c){
	if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' ||
		c == 'o' || c == 'O' || c == 'u' || c == 'U')
		return 1;
	else return 0;
}

void strnoV (char s[]){
	int i = 0, j = 0;
	while (s[i]){
		if (isVogal(s[i])){
			j = i;
			while (s[j]){
				s[j] = s[j+1];
				j++;
			}
		}
		else i++;
	}
}

void truncW (char s[], int n){
	int i = 0, count = 0, j;
	while (s[i]){
		if (s[i] == ' ')
			count = 0;
		else {
			count++;
			if (count > n){
				j = i;
				while (s[j]){
					s[j] = s[j+1];
					j++;
				}
				i--;
			}
		}
		i++;
	}
}

char charMaisfreq (char s[]){
	char res;
	int freq = 0, i = 0,j,count;
	if (s[i] == '\0')
		return 0;
	else {
		while (s[i]){
			count = 0;
			for (j = 0; s[j] ;j++)
				if (s[j] == s[i]) count++;
			//printf("%c %d\n",s[i],count);
			if (count > freq){
				res = s[i];
				freq = count;
			}
			i++;
		}
	} 
	return res; 
}

int iguaisConsecutivos (char s[]){
	int max = 0,i = 0, count = 1;
	while (s[i]){
		if (s[i] == s[i+1])
			count++;
		else {
			if (count > max) max = count;
			count = 1;
		}
		i++;
	}
	return max;
}

int not_in_prev(char str[], int k, int n) {
    int ans = 1;
    for(int i = k; i < n; i++) {
        if(str[i] == str[n]) {
            return 0;
        }
    }
    return ans;
}

int difConsecutivos(char s[]) {
    int ans = 0;
    for(size_t i = 0; s[i]; i++) {
        int consec = 0;
        for(size_t j = i; s[j]; j++) {
            if(not_in_prev(s,i,j)) consec++;
            else break;
        }
        if (consec > ans) ans = consec;
    }
    return ans;
}

int maiorPrefixo (char s1 [], char s2 []){
	int res = 0;
	for (int i = 0; s1[i] == s2[i];i++) res++;
	return res;
}

int maiorSufixo (char s1 [], char s2 []){
	int res = 0;
	for (int i = 0; s1[i]; i++);
	for (int j = 0; s2[j]; j++);
	i--;j--;
	while (s1[i] == s2[j] && i>=0 && j>=0){
		res++;
		i--;
		j--;
	}
	return res;
}

int sufPref (char s1[], char s2[]) {
    int ans = 0, i, j = 0;
    for(i = 0; s1[i]; i++) {
        if(s1[i] == s2[j++]) ans++;
        else ans = j = 0;
    }
    return ans;
}

int contaPal (char s[]){
	int pal = 0, i = 0;
	while (s[i]){
		if (s[i] != ' ' && s[i] != '\n' && (s[i+1] == ' '|| s[i+1] == '\0'))
			pal++;
		i++;
	}
	return pal;
}

int contaVogais (char s[]){
	int res = 0, i = 0;
	while (s[i]){
		if (isVogal(s[i])) res++;
		i++;
	}
	return res;
}

int contida (char a[], char b[]){
	int res = 1, i = 0,j ;
	int ocorre = 0;
	while (a[i] && res){
		// testar se ocorre em b
		ocorre = 0;
		for (j = 0; b[j] && !ocorre ; j++)
			if (b[j] == a[i]) ocorre =1;
		if (ocorre == 0) res = 0;
		i++;
	}
	return res;
}

int palindorome (char s[]){
    int len = 0, res = 1,i;
    for(i = 0; s[i]; i++) len++;
    for(i = 0; s[i]; i++) if (s[i] != s[len-1-i]) res = 0;
    return res;
}

int remRep (char x[]){
	int i = 0,j;
	while (x[i]){
		if (x[i] == x[i+1]){
			for (j = i; x[j]; j++)
				x[j] = x[j+1];
		}
		else i++;
	}
	return i;
}

int limpaEspacos (char x[]){
	int i = 0,j;
	while (x[i]){
		if (x[i] == ' ' && x[i+1] == ' '){
			for (j = i; x[j]; j++)
				x[j] = x[j+1];
		}
		else i++;
	}
	return i;
}
 
// 26 
void insere (int v[], int N, int x) {
    for(int i = 0; i < N; i++) {
        if(v[i] > x) {
            for(int j = N; j > i; j--) {
                v[j] = v[j - 1];
            }
            v[i] = x;
            break;
        }
        if(i == N - 1) {
            v[N] = x;
        }
    }
}

// 27

void merge (int r [], int a[], int b[], int na, int nb) {
    int i = 0, j = 0, k = 0;
    while(k < na + nb) {
        if((a[i] < b[j] && i < na) || j >= nb)
            r[k++] = a[i++];
        else
            r[k++] = b[j++];
    }
}

void recursive_merge(int r[], int a[], int b[], int na, int nb) {
    if(na > 0) {
        if(nb > 0) {
            if(*a > *b) {
                *r = *b;
                recursive_merge(r+1, a, b+1, na, nb-1);
            }
            else {
                *r = *a;
                recursive_merge(r+1, a+1, b, na-1, nb);
            }
        }
        else {
            *r = *a;
            recursive_merge(r+1, a+1, b, na-1, nb);
        }
    }
    else if(nb > 0) {
        *r = *b;
        recursive_merge(r+1, a, b+1, na, nb-1);
    }
}

// 28

int crescente (int a[], int i, int j) {
    int cresc = 1;
    for(int k = i; k < j; k++) {
        if(a[k + 1] < a[k]) cresc = 0;
    }
    return cresc;
}

// 29

int retiraNeg (int v[], int N) {
    int i = 0;
    while(i < N) {
        if(v[i] < 0) {
            for(int j = i; j < N - 1; j++) v[j] = v[j + 1];
            N--;
        }
        else i++;
    }
    return N;
}

// 30

int menosFreq (int v[], int N) {
    int freq = 1, minFreq = N, ans = v[0], i;
    for(i = 1; i < N; i++) {
        if(v[i] == v[i - 1]) freq++;
        if(v[i] != v[i - 1]) {
            if(freq < minFreq) {
                minFreq = freq;
                ans = v[i - 1];
            }
            freq = 1;
        }
    }
    if(freq < minFreq) {
        minFreq = freq;
        ans = v[i - 1];
    }
    return ans;
}

// 31

int maisFreq (int v[], int N) {
    int freq = 1, maxFreq = 0, ans = v[0];
    for(int i = 1; i < N; i++) {
        if(v[i] == v[i - 1]) freq++;
        if(v[i] != v[i - 1]) {
            if(freq > maxFreq) {
                maxFreq = freq;
                ans = v[i - 1];
            }
            freq = 1;
        }
    }
    return ans;
}

// 32

int maxCresc (int v[], int N) {
    int ans = 1, currAns = 1;
    for(int i = 1; i < N; i++) {
        if(v[i - 1] > v[i]) {
            ans = currAns > ans ? currAns : ans;
            currAns = 1;
        }
        else {
            currAns++;
        }
    }
    ans = currAns > ans ? currAns : ans;
    return ans;
}

// 33

int elimRep (int v[], int n) {
    int i = 1;
    while(i < n) {
        int belongs = 0;
        for(int j = 0; j < i; j++) {
            if(v[i] == v[j]) belongs = 1;
        }
        if(belongs) {
            for(int j = i; j < n; j++) {
                v[j] = v[j + 1];
            }
            n--;
        } else i++;
    }
    return n;
}

// 34

int elimRepOrd (int v[], int n) {return elimRep(v,n);}

// 35

int comunsOrd (int a[], int na, int b[], int nb) {
    int i = 0, j = 0, ans = 0;
    while(i < na && j < nb) {
        if(a[i++] == b[j++]) {
            ans++;
            i++;
            j++;
        }
        else if(a[i] > b[j]) j++;
        else i++;
    }
    return ans;
}

// 36

int comuns (int a[], int na, int b[], int nb) {
    int ans = 0;
    for(int i = 0; i < na; i++) {
        int belongs = 0;
        for(int j = 0; j < nb; j++) if(a[i] == b[j]) belongs = 1;
        if(belongs) ans++;
    }
    return ans;
}

// 37

int minInd (int v[], int n) {
    int minIndex = 0;
    for(int i = 1; i < n; i++) 
        if(v[i] < v[minIndex]) 
            minIndex = i;
    return minIndex;
}

// 38

void somasAc (int v[], int Ac [], int N) {
    for(int i = 0; i < N; i++) {
        Ac[i] = 0;
        for(int j = 0; j <= i; j++) {
            Ac[i] += v[j];
        }
    }
}

// 39

int triSup (int N, float m [N][N]) {
    int x = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(m[i][j]) x = 0;
        }
    }
    return x;
}

// 40

void transposta (int N, float m[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            float temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }
}

// 41

void addTo (int N, int M, int a[N][M], int b[N][M]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            *(*(a + i)+j) += b[i][j];
        }
    }
}

// 42

int unionSet (int N, int v1[N], int v2[N], int r[N]) {
    int len = 0;
    for(int i = 0; i < N; i++) {
        r[i] = v1[i] || v2[i];
        len += r[i];
    }
    return len;
}

// 43

int intersectSet (int N, int v1[N], int v2[N],int r[N]) {
    int len = 0;
    for(int i = 0; i < N; i++) {
        r[i] = v1[i] && v2[i];
        len += r[i];
    }
    return len;
}

// 44

int intersectMSet (int N, int v1[N], int v2[N],int r[N]) {
    int len = 0;
    for(int i = 0; i < N; i++) {
        r[i] = v1[i] < v2[i] ? v1[i] : v2[i];
        len += r[i]; 
    }
    return len;
}

// 45

int unionMSet (int N, int v1[N], int v2[N], int r[N]) {
    int len = 0;
    for(int i = 0; i < N; i++) {
        r[i] = v1[i] + v2[i];
        len += r[i]; 
    }
    return len;
}

// 46

int cardinalMSet (int N, int v[N]) {
    int len = 0;
    for(int i = 0; i < N; i++) len += v[i];
    return len;
}

// 47

typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
    int x, y;
} Posicao;

Posicao posFinal (Posicao inicial, Movimento mov[], int N) {
    for(int i = 0; i < N; i++) {
        Movimento x = mov[i];
        if(x == Norte) inicial.y++;
        if(x == Este) inicial.x++;
        if(x == Sul) inicial.y--;
        if(x == Oeste) inicial.x--;
    }
    return inicial;
}

// 48

int caminho (Posicao inicial, Posicao final, Movimento mov[], int N) {
    int* xi = &inicial.x;
    int* yi = &inicial.y;
    int xf = final.x, yf = final.y, i;
    for(i = 0; i < N; i++) {
        if((*xi) < xf) {
            (*xi)++;
            mov[i] = Este;
        }
        else if ((*xi) > xf) {
            (*xi)--;
            mov[i] = Oeste;
        } 
        else if ((*yi) < yf) {
            (*yi)++;
            mov[i] = Norte;
        }
        else if ((*yi) > yf) {
            (*yi)--;
            mov[i] = Sul;
        }
        else break;
    }
    if(inicial.x != final.x || inicial.y != final.y) return -1;
    else return i;
}

// 49

int manDist(int x, int y, int x0, int y0) {return abs(x - x0) + abs(y - y0);}

int maisCentral (Posicao pos[], int N) {
    int minDist = manDist(pos[0].x,pos[0].y,0,0);
    int ans = 0, i;
    for(i = 1; i < N; i++) {
        if(manDist(pos[i].x,pos[i].y,0,0) < minDist) {
            ans = i;
            minDist = manDist(pos[i].x,pos[i].y,0,0);
        }
    }
    return ans;
}

// 50

int vizinhos (Posicao p, Posicao pos[], int N) {
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(manDist(pos[i].x,pos[i].y,p.x,p.y) == 1) ans++;
    }
    return ans;
}


int main (){
	char * res = malloc(sizeof(char *));
	int res1;
	//res = "OLA\0";
	char s1[20] = "ola\0";
	char s2[30] = "mundo cruel!";
	//charMaisfreq(s2);
	printf("%c\n",charMaisfreq(s2));
}








