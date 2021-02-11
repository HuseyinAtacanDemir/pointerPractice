//funct pointers and callbacks
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void A(){
	printf("Hello\n");
}

void B(void (*ptr)()){//func pointer as arg
	
	ptr();//call back func that ptr points to
}

//callback func for bubble sort:
//compare two ints, return 1 if first param is greater
//0 if equal
//-1 if second is greater
int ascending(int a, int b){
	if(a>b) return 1;
	else return -1;
}

int descending(int a, int b){
	if(a>b) return -1;
	else return 1;
}

int absoluteAscending(int a, int b){
 	if(abs(a)>abs(b)) return 1;
	return -1;
}

void BubbleSort(int *A, int n, int (*compare)(int,int)){
	int i,j,tmp;
	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(compare(A[j],A[j+1])>0){
				tmp = A[j];
				A[j] = A[j+1];
				A[j+1] = tmp;
			}
		}
	}

}
int compare(const void* a, const void* b){

	int A = *((int*)a);//typecasting to int* and dereferencing
	int B = *((int*)b);

	return A-B;
}

int main(){
	
	/*
		When reference to a func is passed to another func
		then that particular func is called a call-back func
		The idea is named a callback
		A is the callback func in this case
		Why do this?
		look at the bubble sort example and q sort example
		also, based on events, you might wanna call a specific func
	like upon a mouse click call this etc etc
		
	*/
	B(A);
/*	
	Longer way of doing the same,
	since the func name is same as a pointer to 
	that func with same name
	
	void (*p)() = A;
	B(p);
*/

	int i, A[] = {1,5,-7,3,7,-19,8,3,-9};
	int n = sizeof(A)/sizeof(int);
	BubbleSort(A,n,absoluteAscending);
	for(i=0;i<n;i++) printf("%d\n", A[i]);
	
	qsort(A, n, sizeof(int),compare);

	for(i=0;i<n;i++) printf("%d\n", A[i]);
}
