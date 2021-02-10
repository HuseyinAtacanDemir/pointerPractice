#include<stdio.h>
int main(){
	int a;
	int *p;
	p = &a;// p has the address of a, p points to a
	printf("address of p: %p\n", p);
	printf("value that p points to: %d\n", *p);
	/*prints the mem adr that p points to*/
	/*since p can point to anywhere before it is initialized, it can give any value*/
	
	a = 12;
	printf("a: %d\n", a);
	
	printf("a addr: %p\n", &a);
	*p = 120; // dereferencing		
	printf("a: %d\n", a);

}
