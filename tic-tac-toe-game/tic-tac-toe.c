#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#define TRUE 1;
#define FALSE 0;

// array 0 - 8, This array represents tic-tac-toe game table.
int tablePositions[9];
// The playerTurn variable represents which player will play.
int playerTurn = 1; // This variable is used how key to valid which player will play.

// array to storage the players name.
char player1[10];
char player2[10];

// function to return the player name.
char playerName(void);

// procedure to receive the player name.
void receiveName(void);

// print player name.
char * printNamePlayer(void);

// procedure for valid which player will play.
void validTurn(void);

// possible moves for the player.
enum moves {empty = 0, firstPlayer = 1, secondPlayer = 2};

// player movement.
int playerMovement;

// procedure to print tic-tac-toe table.
void printTable(void);

// procedure to print alls table possitions.
void printfPositions(void);

// procedure to value game moves.
int valueMoves(void);

// insert value in tic-tac-toe table.
void insertValueInTable(void);

// procedure to testing moves.
int testingMoves(void);

// procedure to validation draw.
int drawCase(void);

// procedure to valid which player win.
void gameStatus(void);

int main() {
	
	int counter;
	
	for (counter = 0; counter <= 8; counter++) {
		tablePositions[counter] = 0;
	}
	
	receiveName();
	
	for (counter = 0; counter <= 8; counter++) {
		
		do {
		
			system("cls");
			printf("\nEstado atual da tabela\n");
			printTable();
			printf("\nPosicoes na table\n");
			printfPositions();
			printf("\n%s digite a posicao a qual queira jogar: ", printNamePlayer());
			scanf("%d", &playerMovement);
			getchar();
			
		} while (valueMoves() != 1);
		
		insertValueInTable();
		
		if (testingMoves() == 1) {
			break;
		} else {
			validTurn();	
		}	
	
	}
	
	gameStatus();
		
	return 0;
}

// procedure to receive the players name.
void receiveName(void) {
	
	printf("Digite o nome do primeiro jogador: ");
	scanf("%s", player1);
	printf("Digite o nome do segundo jogador: ");
	scanf("%s", player2);
	getchar();
	
}

// function to return which player will play, this function return the player name.
char * printNamePlayer(void) {
	
	if (playerTurn == 1) {
		return player1;
	}
	
	if (playerTurn == 2) {
		return player2;
	}
	
}

// procedure to validate which player will play.
void validTurn(void) {
	
	if (playerTurn == 1) {
		// this value represents which
		// player will play in the next round.
		playerTurn = 2;
	} else {
		playerTurn = 1;
	}
	
}

// procedure to print table in console.
void printTable(void) {
	
	int counter;
	
	printf("\n");
	
	for (counter = 0; counter <= 8; counter++) {
		
		switch (tablePositions[counter]) {
			case 0:
				printf("|   ");
				break;
			case 1:
				printf("| X ");
				break;
			case 2:
				printf("| O ");
				break;
			default:
				break;
		}
		
		if ((counter + 1) % 3 == 0) {
			printf("|\n");
		}
	
	}
	
}

// procedure to print alls possibles moves.
void printfPositions(void) {
	
	int counter;
	
	for (counter = 0; counter <= 8; counter++) {
		
		printf("| %d ", counter);
		
		if ((counter + 1) % 3 == 0) {
			printf("|\n");
		}
	
	}
	
}

// function to valid move.
int valueMoves(void) {
	
	int validMove;
	
	if (playerMovement >= 0 && playerMovement <= 8) {
		
		if (tablePositions[playerMovement] == 0) {
			validMove = TRUE;
		} else {
			validMove = FALSE;
		}
		
	} else {
		validMove = FALSE;
	}
	
	return validMove;
	
}

// produre to add move in tic-tac-toe table.
void insertValueInTable(void) {
	
	// include the movement in the table 
	tablePositions[playerMovement] = playerTurn;
	
}

// function to tests alls moves to win the game.
int testingMoves(void) {
	
	int endGame = FALSE; // validation if this game finished.
	
	if (tablePositions[0] == 1 && tablePositions[4] == 1 && tablePositions[8] == 1) {
		endGame = TRUE;
	} else {
		if (tablePositions[0] == 2 && tablePositions[4] == 2 && tablePositions[8] == 2) {
			endGame = TRUE;
	    }
	}
	
	if (tablePositions[2] == 1 && tablePositions[4] == 1 && tablePositions[6] == 1) {
		endGame = TRUE;
	} else {
		if (tablePositions[2] == 2 && tablePositions[4] == 2 && tablePositions[6] == 2) {
			endGame = TRUE;
	    }
	} 
		
	if (tablePositions[0] == 1 && tablePositions[1] == 1 && tablePositions[2] == 1) {
		endGame = TRUE;
	} else {
		if (tablePositions[0] == 2 && tablePositions[1] == 2 && tablePositions[2] == 2) {
			endGame = TRUE;
	    }
	}
	
	if (tablePositions[3] == 1 && tablePositions[4] == 1 && tablePositions[5] == 1) {
		endGame = TRUE;
	} else {
		if (tablePositions[3] == 2 && tablePositions[4] == 2 && tablePositions[5] == 2) {
			endGame = TRUE;
	    }
	}
	
	if (tablePositions[6] == 1 && tablePositions[7] == 1 && tablePositions[8] == 1) {
		endGame = TRUE;
	} else {
		if (tablePositions[6] == 2 && tablePositions[7] == 2 && tablePositions[8] == 2) {
			endGame = TRUE;
	    }
	}
	
	if (tablePositions[0] == 1 && tablePositions[3] == 1 && tablePositions[6] == 1) {
		endGame = TRUE;
	} else {
		if (tablePositions[0] == 2 && tablePositions[3] == 2 && tablePositions[6] == 2) {
			endGame = TRUE;
	    }
	}
	
	if (tablePositions[1] == 1 && tablePositions[4] == 1 && tablePositions[7] == 1) {
		endGame = TRUE;
	} else {
		if (tablePositions[1] == 2 && tablePositions[4] == 2 && tablePositions[7] == 2) {
			endGame = TRUE;
	    }
	}
	
	if (tablePositions[2] == 1 && tablePositions[5] == 1 && tablePositions[6] == 1) {
		endGame = TRUE;
	} else {
		if (tablePositions[2] == 2 && tablePositions[5] == 2 && tablePositions[6] == 2) {
			endGame = TRUE;
	    }
	}
	
	return endGame;
	
}

int drawnCase(void) {
	
	int counter;
	int testGame = 0;
	
	for (counter = 0; counter <= 8; counter++) {
		
		if (tablePositions[counter] == 0) {
			testGame++;
		}
	}
	
	// value 8 in testGame represent table FULL.
	if (testGame == 8) {
		return 1;
	} else {
		return 0;
	}
	
}

void gameStatus(void) {
	
	system("cls");
	printTable();
	
	if (drawnCase() == 1) {
		printf("\n\aOcorreu um empate empate!\n");
	} else {	
		printf("\n\a%s venceu o jogo!", printNamePlayer());
		
	}
	
}
