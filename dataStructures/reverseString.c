#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int notLetter(char c){

	if((c >= 65 && c <=90 )||(c >= 97 && c <= 122)) return 0;
	return 1;
}

char * reverseOnlyLetters(char * S){


	int len = strlen(S);
	
	char *l = S;
	char *r = S+len-1;

	while(l != r){
		
		while(notLetter(*l)) l++;
		if(l>=r) break;
		while(notLetter(*r)) r--;
		
		char tmp = *l;
		*l = *r;
		*r = tmp;
		
		l++;
		r--;
	}
	


	return S;

}
int main(){

	char * C = (char*)malloc(7*sizeof(char));
	
	C[0] = 'a';
	C[1] = 'b';
	C[2] = '1';
	C[3] = '2';
	C[4] = 'c';
	C[5] = 'd';
	C[6] = '\0';

	printf("%s\n", reverseOnlyLetters(C));
	
	free(C);
}
