#include<stdio.h>
#include<stdlib.h>
int main(){

	int a; //goes on stack

	int *p;
	p = (int*)malloc(sizeof(int));
	*p = 10;
	free(p); //now I have deallocated it.

	//malloc looks for a space on heap, tells how much memory to allocate by size. malloc returns an address of the start of the allocated space on heap.

	//only way to use mem on heap is through reference.

	p = (int*)malloc(sizeof(int));
	*p = 20;

	//the mem allocated before is not deallocated,
	//so it is wasted space now.
	//whenever you are done ith using the heap, deallocate or free the mem you requested in the first place.
	//c doesn't have a garbage collector like some other langs.
	free(p);
	p = (int*)malloc(20*sizeof(int));
	//if malloc cannot find free space on the heap, it returns null

		
	free(p);
}
