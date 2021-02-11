#include<stdio.h>
int main(){

	int a = 1025;
	int *p;
	
	p = &a;
	printf("size of integer is %d bytes\n", sizeof(int));
	printf("Address = %d, value = %d\n", p, *p);
	
	void *p0;
	
	p0 = p;

	//cannot dereference void pointer
	//printf("Address = %d, value = %d\n", p0, *p0);
	//we would get a compilation error
	//c standard wouldn't allow dereferencing void pointers
	//it also wouldn't allow pointer airthmetic on them
	//but gnu c allows it and increments the void pointer by one byte.
	//so depending on the compiler, one might do different things
	printf("address = %d\n", p0);
	printf("address = %d\n", p0+1);

}
