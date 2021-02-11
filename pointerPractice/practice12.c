#include<stdio.h>
void foo(int (*p)[2][2]){
	printf("in foo\n");
}
int main(){

        int B[2][3] = {{1,2,3},{4,5,6}};
        //it is not really a 2d arr
        //it is 2 1d arrays of size 3
        //first B[0] is placed in memory
        //then B[1]

        //int *p = B; would give an error
        //since B is a pointer to a 1d arr of 3 ints
        int (*p)[3] = B;
        
	printf("B is a pointer to a int[] %d\n",B);
	printf("*B is a pointer to a int %d\n",*B);
	printf("&B[0] is adrs of B[0] %d\n",&B[0]);
	printf("&B[0][0] is adrs of B[0][0] %d\n",&B[0][0]);
	printf("**B is val of B[0][0] %d\n",**B);

	int C[3][2][2] = {
	{{2,5},{7,9}},
	{{3,4},{6,1}},	
	{{0,8},{11,13}}
	};

	printf("%d\n", *(*(*(C+2)+0)+1));
	//C+2 --> pointer to the last 2d arr of type int*[][]
	//*(C+2)+0 pointer to the first 1d arr of the last 2d arr,
	//pointer of type int*[]
	//*(*(C+2)+0)+1 pointer to the last element of type int of the first 1d arr of the last 2d arr of the 3d arr 

	//C[i][j][k] ===
	//*(C[i][j]+k) ===
	//*(*(C[i]+j)+k) ===
	//*(*(*(C+i)+j)+k)
	foo(C);

}
