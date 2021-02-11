#include<stdio.h>
#include<stdlib.h>

int main(){

	int n;
	printf("size of arr\n");
	scanf("%d", &n);

	int *A = (int*)malloc(n*sizeof(int));

	for(int i = 0; i < n; i++){
		A[i] = i+1;
	}
	/*
	free(A);
	A[2] = 6;
	you might or might not be able to access the mem
	you have previously freed
	depends on compiler os...
	*/
	int *B = (int*)realloc(A, 2*n*sizeof(int));
	printf("prev bloc adrs: %d, new block adrs: %d", A, B);
	for(int i = 0; i < 2*n; i++){
               printf("%d\n", B[i]);
        }
	
	//int *B=(int*)realloc(A,0); same as free(A)
	//int *B=(int*)realloc(NULL,n*sizeof(int)) same as malloc
	


}
