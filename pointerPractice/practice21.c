//memory leaks: caused by improper use of memory
//when you use memory and don't free it after
//simple betting game
// jack queen king --comp shuffles these cards
//player has to guess the poisition of the queen
//if he wins, he takes 3*bet
//if he loses he loses the bet amount
//has 100$ initially


/*

in this implementation of the game, the car array is dynamically allocated on the heap. This would not constitute an issue on its own, but in this implementation, the allocated memory is not freed before play returns. So the next time play is called the previously allocated mem block is still in the heap, and we have no pointer to it cause we now use that pointer to point to a new allocated block on the heap. So we leak the mempry of the previous char arrays every time we call play.. You'll see that the memory consumption of this file will rise on your task manager or activity monitor...

see practice20.c to learn how to manage it properly

*/
#include<stdio.h>
#include<stdlib.h>
int cash = 100;
void Play(int bet){

	//char C[3] = {'J','Q','K'};
	char *C = (char*)malloc(1000000*sizeof(char));
	*C = 'J';
	*(C+1) = 'Q';
	*(C+2) = 'K';
	printf("shuffling...\n");
	srand(time(NULL));

	int i;
	for(i = 0; i < 5; i++){
		int x = rand() % 3;
		int y = rand() % 3;
		int temp = C[x];
		C[x] = C[y];
		C[y] = temp;
	
	}
	int playerGuess;
	printf("Guess, 1 2 or 3\n");
	scanf("%d", &playerGuess);

	if(C[playerGuess-1] == 'Q'){
		cash += 3*bet;
		printf("You guessed right! %c%c%c Cash: %d\n", C[0],C[1],C[2],cash);
	}else{
		cash -= bet;
		printf("You guessed wrong! %c%c%c Cash: %d\n", C[0],C[1],C[2],cash);
	}

}

int main(){

	int bet;
	while(cash > 0){
		printf("bet? $");
		scanf("%d", &bet);
		printf("\n");
		
		if(bet==0 || bet > cash) break;
		Play(bet);
	}



}
