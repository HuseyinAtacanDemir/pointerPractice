#include<stdio.h>
int main(){

	int A[] = {2,4,5,8,1};

	printf("A    : %d\n", A);
	printf("&A[0]: %d\n", &A[0]);
	printf("A[0] : %d\n", A[0]);
	printf("*A   : %d\n", *A);

	printf("\nlooping:\n");

	int i;
	for(i = 0; i < 5; i++){
		printf("Adrs &A[i]: %d\n", &A[i]);
		printf("Adrs   A+i: %d\n", A+i);
		printf("Val   A[i]: %d\n", A[i]);
		printf("Val *(A+i): %d\n\n", *(A+i));
	}
	
	//we could say something like:
	int *p = A;
	//p++;
	//but we cannot do A++;
	printf("A: %d p: %d\n", A, p);	

}
