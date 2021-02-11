//arrays as func args
#include<stdio.h>

int sumArr(int A[], int size){
	int i, sum = 0;
	for(i = 0; i<size; i++){
		sum += A[i];
	}

	return sum;

}

//this is call by reference, arrays are always passed as references
//the compiler implicitly converts int A[] to int* A
//that is why it's size is 8 bytes (in my 64x machine)
int sumArr2(int A[]){
        int i, sum = 0;
	int size = sizeof(A)/sizeof(A[0]);
	printf("SA2 - Size of A = %d, size of A[0] = %d\n", sizeof(A), sizeof(A[0]));
        for(i = 0; i < size; i++){
                sum += A[i];
        }
	printf("%d %d\n", A, A+1);

        return sum;

}

void Double(int* A, int size){

	//since we have the pointer, we know the adrs 
	//of elements in A
	//so we modify the value at the adrs
	//so the modifications are reflected in Main
	//also
	int i;
	for(i = 0; i < size; i++){
		A[i] *= 2;
	}
}

int main(){

	int A[] = {1,2,3,4,5};
	int size = sizeof(A)/sizeof(A[0]);
	
	int sum = sumArr(A,size);
	printf("Sum of Elements: %d\n", sum);


	
	int sum2 = sumArr2(A);
        printf("Sum of Elements2: %d\n", sum2);

	printf("MAIN- Size of A = %d, size of A[0] = %d\n", sizeof(A), sizeof(A[0]));

	printf("%d %d\n", A, A+1);

	int x = 0;
	int *p = &x;
	printf("%d %d\n", sizeof(x), sizeof(p));

	Double(A, size);
	
	for(int i = 0; i < size; i++){
		printf("%d\n", A[i]);
	}

}
