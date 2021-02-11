#include<stdio.h>
int Add(int a, int b){
	return a+b;
}
void PrintCustom(char *str){
	printf("%s\n", str);
}
int *Func(int,int);//declaring a func that returns an int*
int main(){

	int c;
	//pointer to function that takes (int,int) params
	int (*p)(int,int);

	//int *p(int,int);
	//now it is a declaration of a func that returns int*
	
	//void *p(int,int) wont work for Add
	//the pointer needs to match the func that you're gonna assign to it
	
	p = &Add;
	//p = Add; this means the same thing also
	//func name on its own would also return a pointer
	//to the function
	
	//dereferencing and executing the function
	c = (*p)(2,3);
	//c = p(2,3); would work also for dereferencing

	printf("%d\n",c);


	void (*ptr)(char*);

	ptr = PrintCustom;
	
	ptr("Test String");
}
