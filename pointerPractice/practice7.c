#include<stdio.h>
//Increment is the called function
//the a in Increment is caled the formal argument
void Increment(int a){
	a = a+1;
	printf("Address of variable a in Increment = %d\n", &a);
}


void IncrementP(int *p){

	*p = (*p) + 1;
}

int main(){
	int a;
	a = 10;
	//this is a call by value func call
	Increment(a);
	printf("Address of variable a in Main Func = %d\n", &a);
	//main is the calling function
	//the int a that main passes to Increment is called the actual arguement, and only the value of a is passed to Increment.
	
	//what about this:
	printf("value of a before IncrementP: %d\n", a);
	//this is a call by reference func
	IncrementP(&a);
	printf("Value of a after IncrementP: %d\n", a);
}
