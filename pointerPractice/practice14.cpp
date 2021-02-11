#include<stdio.h>
#include<stdlib.h>
#include<iostream>
int main(){
	//same code on c++
	int a; //goes on stack
	int *p;
	
	p = new int;
	*p = 10;
	delete p;

	p = new int[20];
	delete[] p;

	std::cout << "Using new and delete\n";
	return 0;
}
