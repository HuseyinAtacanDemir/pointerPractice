#include<stdio.h>
#include<stdlib.h>

int main(){

	//malloc calloc realloc free
	//malloc: returns void*, allocate memory return first byte of mem block
	//malloc doesnt initialize the bytes it allocates
	//in order to use that memory, we ned to typecast the void pointer returned by malloc

	int *p = (int*)malloc(3*sizeof(int));
	p[0] = 1;
	*(p+1) = 2;
	p[2] = 3;
	
	free(p);

	//calloc: void*, two args: num of elements, size of one elem
	//calloc initializes bytes with 0
	
	int n;
	char c;
	printf("Enter size of array:\n");
	scanf("%d", &n);
	printf("type c for calloc, m for malloc:\n");
	scanf(" %c", &c);

	int *A;
	//we cannot just do int A[n];
	//so we need to dynamically allocate it
	if(c == 'm'){
		printf("malloc:\n");
		A = (int*)malloc(n*sizeof(int));
	}else{
		//using calloc instead
		A = (int*)calloc(n,sizeof(int));
	}
	
	printf("before initialization:\n\n");
	for(int i = 0; i < n; i++){

                printf("%d\n",*(A+i));
        }
	
	for(int i = 0; i < n; i++){
		*(A+i) = i+1;
	//lets not initialize them to see the diff tween malloc calloc
	}
	printf("\n after initializaiton\n\n");	
	for(int i = 0; i < n; i++){

		printf("%d\n",*(A+i));
	}
	free(A);
}


/*
the point of the last couple lines of code was to see how calloc initializes the mem unlike malloc
	However, I failed to see the effects from the console output of my code
	regardless of what I used, they would show the contents as zero even before initialization, even with malloc

So I googled it
	
	Turns out malloc does not initialize them to zero

	but, most likely you'll get zeroes:
	here is how:
	
	When you call malloc(), one of two things will happen:

It recycles memory that was previous allocated and freed from the same process.
It requests new page(s) from the operating system.
In the first case, the memory will contain data leftover from previous allocations. So it won't be zero. This is the usual case when performing small allocations.

In the second case, the memory will be from the OS. This happens when the program runs out of memory - or when you are requesting a very large allocation. (as is the case in your example)

Here's the catch: Memory coming from the OS will be zeroed for security reasons.*

When the OS gives you memory, it could have been freed from a different process. So that memory could contain sensitive information such as a password. So to prevent you reading such data, the OS will zero it before it gives it to you.

	https://stackoverflow.com/questions/8029584/why-does-malloc-initialize-the-values-to-0-in-gcc

*/
