#include<stdio.h>
//pointers are strongly typed,
//because we don't use them just to access mem locations
//we use them to create arrays etc.. 
//we also use them to dereference
//so they need to be of the size of the type they point to.
int main(){
	int a = 1025;
	int *p;
	p = &a;
	//this just prints the addrs of starting byte of the 
	//4 bytes of space that was allocated to int a
	printf("adr of p: %d\n",p);
	printf("adr of p+1: %d\n",p+1);
	//this prints the integer value stored starting at the memory addr that p points to.
	//therefore in order to properly read the value from memory
	//the compiler needs to know that p points to an int
	//so that it'll read 4 bytes from the starting byte
	printf("val of *p : %d\n", *p);
	
	char *c;
	c = (char*) p;
	printf("adr of c: %d\n",c);
	printf("adr of c+1: %d\n",c+1);
	printf("val of c: %d\n", *c);
	printf("val of c+1: %d\n",*(c+1));
	//0000000 0000000 00000100 00000001
	//c+1 points to the second byte, which on its own would be read as four


}
