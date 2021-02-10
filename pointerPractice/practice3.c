#include<stdio.h>
int main(){
	int a = 10;
	int *p;
	p = &a;
	//pointer arithmetic
	printf("address of p: %d\n", p);
	printf("value of p: %d\n", *p);
	printf("size of an integer is %d bytes\n", sizeof(int));
	printf("address of p+1: %d\n", p+1);
	printf("value of p+1: %d\n", *(p+1));
	//p is a int pointer, so when you increment,
	//it increases by the size of an int
	// vis a vis 4 bytes.
	//the next addressable int space is 4 bytes awa
	
}
