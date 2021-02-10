#include<stdio.h>
int main()
{
	int a;
	int *p;

	a = 10;
	p = &a; //&a : address of a
	
	int b = 20;
	printf("val of a: %d\n",a);
	*p = b; //will the address in p change to point b?
	printf("val of a: %d\n",a);
	printf("adr of a: %p\n",&a);
	
	printf("adr in p: %p\n",p);
	p = &b;
	printf("p = &b\n");
	printf("adr in p: %p\n",p);	
}
