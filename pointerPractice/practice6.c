#include<stdio.h>
int main(){

	int x = 5;//4 bytes allocated for x
	int *p = &x;//8 bytes allocated to p itself in order to record the address of x (in a x64 architecture)
	//we don't just record the address of a var in a pointer, we also record it's length.
	
	*p = 6;//now x is 6

	//what about a pointer to p itself?

	int **q = &p;//now q has the address of pointer p
	//now q is a pointer to a pointer 
	
	int ***r = &q;
	//r cannot store the address of p or x
	
	printf("val at adr p: %d\n",*p);//value stored at adr p

	printf("val at adr stored in q: %d\n",*q);//value at adr stored in q
	//since p is a pointer to int x
	//the value of p is the adr of x
	//so *q gives us adr of x
	printf("adr of x: %d\n", &x);
	
	printf("dereferencing  **int: %d\n", **q);
	printf("dereferencing  **int: %d\n", **r);
	printf("dereferencing ***int: %d\n", ***r);

	printf("*r: %d,\n q: %d,\n&p: %d\n",*r,q,&p);//value stored at adr r
	//r stores the adr of q
	//*r has the value at q
	//q stores the adr of p
	//so *r will be the adr of p

	//lets modify x using r and a chain of dereferencing
	***r = 10; 
	//get the value r points to to, get thta value's value, then get that value's value, set it to 10.
	//r points to q, q points to p, p points to x, then change x
	printf("%d\n", x);


	//what about this?
	**q = *p + 3;
	//what will be the outcome?
	//**q dereferences first to p, then dereferences to x
	//*p is a dereference to x also,
	//so this statement is equivalent to
	//x = x+3;
	printf("%d\n",x);
}
