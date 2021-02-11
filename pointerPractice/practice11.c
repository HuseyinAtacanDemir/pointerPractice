#include<stdio.h>
int main(){

	int B[2][3] = {{1,2,3},{4,5,6}};
	//it is not really a 2d arr
	//it is 2 1d arrays of size 3
	//first B[0] is placed in memory
	//then B[1]

	//int *p = B; would give an error
	//since B is a pointer to a 1d arr of 3 ints
	int (*p)[3] = B;
	printf("B    : %d\n&B[0]: %d\n", B, &B[0]);
	//pointer to the first 1d arr
	printf("*B   :%d\nB[0] :%d\n", *B, B[0]);
	
	printf("sizeof(B)%d\nsizeof(*B)%d\n", sizeof(B), sizeof(*B));
	

	//for a 2d array: B[i][j] is equivalent to:
	// *(B[i] + j)
	// we know that in a 1d arr B[i] would be equivalent to B + i
	//so *(B[i] + j) === *(*(B + i) + j)

	
}
