//char arrs and pointers

#include<stdio.h>
#include<string.h>

void print(char* C){

	int i = 0;

	while(C[i] != '\0'){
		printf("%c", C[i]);
		i++;
	}
	printf("\n");
}
void printMod(char* C){

        int i = 0;

        while(*C != '\0'){
                printf("%c", *C);
                C++;
        }
        printf("\n");
}

int main(){
//store strings: store char arrays
//size of arr >= no of chars in string +1

//strings need to be terminated with a null

	char C[4];
	C[0] = 'J';
        C[1] = 'O';
        C[2] = 'H';
        C[3] = 'N';

	char S[5];
	S[0] = 'J';
        S[1] = 'O';
        S[2] = 'H';
        S[3] = 'N';
        S[4] = '\0';
	printf("%s\n%s\n",C,S);


	int lenC = strlen(C);
        int lenS = strlen(S);
	printf("%d\n%d\n", lenC, lenS);

	char str[] = "John";
	int lenStr = strlen(str);
	printf("Size in Bytes: %d\nLength: %d\nString: %s\n", lenStr, sizeof(str), str);

//arrays and pointers are different types that are used in similar ways

	char c1[6] = "hello";
	char* c2;
	c2 = c1;
	printf("%c\n",c2[1]);

//printing char with %s would give a segmentation fault
//cause %s expects a pointer to a char arr
//so looks for the mem adr of whatever ascii code that was passed
//ascii codes of course give a low level mem adrs
//hence the seg fault

	c2[0] = 'a';
	*(c2+1) = 'b';
	*(c1+2) = 'c';

//c1 = c2; would not work
//c1++; would not work
	
	c2++;
	*c2 = 'n';
	printf("%s\n",c1);


	char c2p[20] = "excercise";//string literal, null term is implicit
	print(c2p);
	
	printMod(c2p);

	char *consChar = "Hello";
	//string gets stored as a constant
	//consChar[0] = 'a' would crash.
	printMod(consChar);
	

/*

*/
}
