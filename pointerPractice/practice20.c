//memory leaks: caused by improper use of memory
//when you use memory and don't free it after
//simple betting game
// jack queen king --comp shuffles these cards
//player has to guess the poisition of the queen
//if he wins, he takes 3*bet
//if he loses he loses the bet amount
//has 100$ initially


/*

in this implementation of the game, all the vars are on the stack
so the memory consumption, if you look at task manager or activity monitor, is constant

see practice21.c to learn what happens if you don't manage memory properly...

*/
#include<stdio.h>
#include<stdlib.h>
int cash = 100;
void Play(int bet){

	char C[3] = {'J','Q','K'};
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
