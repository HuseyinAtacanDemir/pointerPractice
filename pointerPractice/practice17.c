//pointers as function returns

#include<stdio.h>
#include<stdlib.h>

//a b and c have the values of x y and z copied into them
//this is a call by value approach
int Add(int a, int b){
	//a b and c are local to Add
	
	int c = a+b;
	return c;
}
int* AddRef(int* x, int* y){

	printf("adrs of x in AddRef: %d\n", &x);
	printf("val of x in main: %d\n", x);
	int z = (*x) + (*y);
	return &z;

}
void customPrint(){
	printf("random bullshit to make a point about stack frame\n");
}

int *AddMalloc(int* a, int*b){

	int* c = (int*)malloc(sizeof(int));
	*c = (*a) + (*b);
	return c;

	
}
int main(){
	//x y and z are local to main
	int x = 2, y = 4;
	int *ptr = AddRef(&x,&y);
	//now we gotta pass the addresses

	customPrint();
	printf("Sum: %d\n", *ptr);
	//after we do the customPrint call,
	// the *ptr probably points at some random stuff in the stack frame
	//that customPrint used
	//so the value that ptr pointed to got messed up
	//as a general rule,
	//ok to pass variable from bottom of the stack to the top
	//but not the other way around

	//if you wanna pass things areound like that
	// you might wanna use heap or the global vars
	//cause global vars can be accessed by all the funcs
	//and heap needs to be manually allocated and deallocated
	// so once you allocate on heap, you can be sure that
	//it's gonna stay there until you yourself deallocate it
	printf("adrs of x in main: %d\n", &x);


	int *ptr2 = AddMalloc(&x,&y);

	customPrint();
	printf("sum = %d\n", *ptr2);

}
