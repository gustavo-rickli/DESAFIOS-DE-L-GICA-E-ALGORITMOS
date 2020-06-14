#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <cstring>

#define TRUE 1;
#define FALSE 0;

// players simbols
char symbolsOnMove[4] = {'X', 'O', 'X', '#'};

// array 0 - 8, This array represents tic-tac-toe game table.
int tablePositions[9];
// The playerTurn variable represents which player will play.
int playerTurn = 1; // This variable is used how key to valid which player will play.

// array to storage the players name.
char player1[10];
char player2[10];

// variable to close program.
char stopProgram;
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
void printTable(char symbolPlayerOne, char symbolPlayerTwo);

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

// storage the historic matches
// index 0 - Player 1 historic
// index 1 - Player 2 historic
// -----------------
// index 2 - Player In matches with IA
// index 3 - IA points
int matchesHistoric[4];
void printHistoricMatches(void);

// procedure to valid which player win.
void gameStatus(void);

void initTable(void);

// configuracoes para iniciar o jogo
void startGame(void);

// Resetar as configurações do console apos o jogo terminar
void endGame(void);

// neste procedimento se encontram todas as regras do jogo com 2 jogadores.
void twoPlayersGame(void);

// titulo do jogo ao inicia-lo.
void printMenu(void);

// procedimento para encerrar programa
void closeProgram(void);

// procedimento para escolher as opcoes do console
void optionsConsole(void);

// Procedimento para as opcoes do jogo
// jogar com dois jogadores ou inteligencia artificial
// configuracoes de tela (COR DE FUNDO E COR DA LETRA)
// Escolher seu ponto (o simbolo que sera usado por vc)
void gameOptions(void);
// procedimento para imprimir o menu do jogo
void menuOptions(void);

// procedimento da tela de start do jogo
void menuGame(void);

// procedimento para alterar o nome dos jogadores
void alterNamePlayer(void);

// procedure to alter symbols used in game
void alterSymbols(void);


// aqui ficara o jogo contra a IA.
void playerVsIaGame(void);

// aqui sera processada a jogada que a IA ira fazer.
void IAMove(void);

// funcao para retornar o movimento que a IA ira escolher
int testMoves();

// funcao recursiva para encontrar o melhor movimento baseada no algoritmo Minimax
int algorithRecursive(int table[], int profundidade, int playerMove);

int main() {

	// iniciar o jogo com as configuracoes padrao do console
	startGame();

	// tela de abertura do jogo
	menuGame();

	// acessar menu principal do jogo
	do {

		// procedimento para exibir as opcoes do jogo
		gameOptions();

		closeProgram();

	} while (stopProgram == 'n' || stopProgram == 'n');

	// fechar programa restaurando as confirações do console para a cor padrão
	endGame();
	getchar();
	return 0;
}

void gameOptions(void) {
	int optionGame;
	
	// variavel com dois valores para controlar o loop 1 [sai do loop] - 0 [continua no lopop]
	int leaveLoop;

	do {
		system("cls");

		printMenu();
		menuOptions();

		printf("\n => ");
		scanf("%d", &optionGame);
		getchar();
		system("cls");
		switch (optionGame) {
			case 1:
				twoPlayersGame();
				leaveLoop = 0;
				break;

			case 2:
				playerVsIaGame();
				leaveLoop = 0;
				break;

			case 3:
				optionsConsole();
				leaveLoop = 0;
				break;

			case 4:
				printHistoricMatches();
				leaveLoop = 0;
				break;

			case 5:
				alterNamePlayer();
				leaveLoop = 0;
				break;

			case 6:
				alterSymbols();
				leaveLoop = 0;
				break;

			default:
				leaveLoop = 1;
				break;
		}

	} while(leaveLoop == 0);
}

void optionsConsole(void) {
	// NOTA:
	// ------------------
	// caso esta solucao nao ocorra demaneira correta,
	// a nova proposta de solução será usar uma estrutura de seleção.
	// ------------------

	char colorValue;

	system("cls");

printf("Table com os codigos das cores do Command Prompt: \n");
printf("0 - Preto\t8 - Cinza\n");	
printf("1 - Azul\t9 - Azul claro\n");	
printf("2 - Verde\tA - Verde claro\n");	
printf("3 - Verde-Agua\tB - Verde-agua claro\n");	
printf("4 - Vermelho\tC - Vermelho claro\n");	
printf("5 - Roxo\tD - Lilas\n");	
printf("6 - Amarelo\tE - Amarelo claro\n");	
printf("7 - Branco\tF - Branco brilhante\n");
printf("L - sair(leave)\n");

	printf("\nCodigo -> ");
	colorValue = getchar();
	getchar();
	
		switch (colorValue) {
			case 0:
				system("color 00");
				break;

			case 1:
				system("color 01");
				break;

			case 2:
				system("color 02");
				break;

			case 3:
				system("color 03");
				break;

			case 4:
				system("color 04");
				break;

			case 5:
				system("color 05");
				break;

			case 6:
				system("color 06");
				break;
				
			case 7:
				system("color 07");
				break;

			case 8:
				system("color 08");
				break;
			
			case 9:
				system("color 09");
				break;

			case 'a':
			case 'A':
				system("color 0a");
				break;

			case 'b':
			case 'B':
				system("color 0b");
				break;

			case 'c':
			case 'C':
				system("color 0c");
				break;

			case 'd':
			case 'D':
				system("color 0d");
				break;

			case 'e':
			case 'E':
				system("color 0e");
				break;

			case 'f':
			case 'F':
				system("color 0f");
				break;

			default:
				break;
		}	
		
	system("cls");
}

void printHistoricMatches(void) {

	printMenu();

	printf("\tPLAYER 1\tPLAYER 2\n");
	printf("\t\t%d\t\t%d\n", matchesHistoric[0], matchesHistoric[1]);
	printf("\n\n");
	printf("\tPLAYER\t\tIA\n");
	printf("\t\t%d\t\t%d\t", matchesHistoric[2], matchesHistoric[3]);
	printf("\n\n");
	printf("-> Pressione qualquer tecla para sair: ");
	getchar();

}

void alterNamePlayer(void) {

	receiveName();

}

void alterSymbols(void) {
	char option;
	char symbol; // represeta qual o jogador que sera alterado o simbolo

	do {
		// primeira etapa
		system("cls");
		printMenu();

		printf("\t[1] Jogador 1\tJ[2] Jogador 2\n\t\t%c\t\t%c\n\n", symbolsOnMove[0], symbolsOnMove[1]);
		printf("\t[3] Humano\t\t[4] Inteligencia Artificial\n\t\t%c\t\t%c\n\n", symbolsOnMove[2], symbolsOnMove[3]);

		printf(" -> Qual simbolo deseja alterar? - Digite [l] ou [L] para sair\n");
		printf(" => ");
		scanf("%c", &option);
		getchar();

		// segunda etapa
		if (option != 'l' && option != 'L') {
			system("cls");

			printMenu();

			printf(" -> Digite o novo simbolo:\n");
			printf(" => ");
			scanf("%c", &symbol);
			getchar();

			switch (option) {
				case '1':
					symbolsOnMove[0] = symbol;
					break;

				case '2':
					symbolsOnMove[1] = symbol;
					break;

				case '3':
					symbolsOnMove[2] = symbol;
					break;

				case '4':
					symbolsOnMove[3] = symbol;
					break;
				
				default:
					break;
			}
		}

	} while(option != 'l' && option != 'L');
}

void playerVsIaGame(void) {
	int counter;

	// aqui estou salvando os nomes originais para
	// depois do jogo contra a IA repassar esses nomes novamente.
	char playerName[10];
	char playerTwoName[10];
 
	strcpy(playerName, player1);
	strcpy(playerTwoName, player2);

	strcpy(player1, "Jogador");
	strcpy(player2, "R2D2");

	// procedimento para iniciar a tabela do jogo
	initTable();
	
	for (counter = 0; counter <= 8; counter += 2) {
		
		do {
		
			system("cls");
			printf("\nEstado atual da tabela\n");
			printTable(symbolsOnMove[2], symbolsOnMove[3]);
			printf("\nPosicoes da tabela\n");
			printfPositions();
			printf("\nJogador digite a posicao a qual queira jogar: ");
			scanf("%d", &playerMovement);
			getchar();
			
		} while (valueMoves() != 1);
		
		insertValueInTable();
		
		if (testingMoves() == 1) {
			break;
		} else {
			validTurn(); // troca o turno para o turno da IA
			IAMove(); // faz a jogada da IA
			insertValueInTable();
			
			if (testingMoves() == 1) {
				break;
			} else {
				validTurn(); // troca o turno para o jogador novamente
			}
		}
	
	}

	gameStatus();	

	printf("\n\nPressione qualquer tecla para continuar...");
	getchar();

	strcpy(player1, playerName);
	strcpy(player2, playerTwoName);
}

void IAMove(void) {
	
	playerMovement = testMoves();

}

// esta funcao ira retorna o movimento adequando para o computador jogar
int testMoves() {
	int counter;
	int i;
	// array com os valores de cada jogada para tomar a melhor decisao
	// os valores do array estao de acordo com o array do tabuleiro
	// por isso precisa apenas retornar o index do array.
	int valuesOnRecursion[8];

	// eh preciso marcar a opcao antes de chamar o algoritmo,
	// afinal esse tipo de algorit ira partir de uma jogada livre no tabuleiro,
	// cada jogada o algoritmo ira testar todas as possibilidades e retornar
	// um numero baseado em cada resultado encontrado
	// [1] -> vitoria
	// [0] -> empate
	// [-1] -> derrota
	int copyTablePositions[8];
	int profundidade;
	int index;
	int biggerThan;

	for (counter = 0; counter <= 8; counter++) {
		
		if (tablePositions[counter] == 0) {
			copyTablePositions[counter] = 2;
			valuesOnRecursion[counter] = algorithRecursive(copyTablePositions, 2, 3);
		}

	}

	for (counter = 0; counter <= 8; counter++) {
		if (biggerThan < valuesOnRecursion[counter]) {
			index = counter;
			biggerThan = valuesOnRecursion[counter];
		}
	}

	return index;
}

int algorithRecursive(int table[], int playerMove, int profundidade) {

	int value;

	if (playerMove == 2) {
		playerMove = 1;
	} else {
		playerMove = 2;
	}
	
	// implements min-max algorithm

}

void menuOptions(void) {
	system("cls");
	printMenu();

	printf("1 - Jogar com dois jogadore\n");
	printf("2 - Jogar contra a IA\n");
	printf("3 - Fazer modificacoes no jogo\n");
	printf("4 - Acessar historico das partidas\n");
	printf("5 - Alterar o nome dos jogadores\n");
	printf("6 - Alterar simbolo usados\n");
	printf("7 - Encerrar o programa\n");
}

void closeProgram(void) {
	system("cls");
	printMenu();
	printf("Deseja encerrar o programa? (s/n)\n");
	printf("=> ");
	scanf("%c", &stopProgram);
}

void menuGame(void) {
	char startGame;	

	do {
		printMenu();

		printf("\n -> Pressione X para iniciar o jogo\n");
		scanf("%c", &startGame);
		getchar();
		system("cls");
	} while (startGame != 'X' && startGame != 'x');

}

void printMenu(void) {
printf("\n");
// primeira linha
printf(" _________   __   _______ \t");
printf(" _________   ________   _______ \t");
printf(" _________   ________   _______ \n");

// segunda linha
printf("|         | |  | |  _____|\t");
printf("|         | |   __   | |  _____|\t");
printf("|         | |   __   | |  _____|\n");

// terceira linha
printf("|__     __| |  | | |      \t");
printf("|__     __| |  |  |  | | |      \t");
printf("|__     __| |  |  |  | | |_____ \n");

// quarta linha
printf("   |   |    |  | | |      \t");
printf("   |   |    |  |__|  | | |      \t");
printf("   |   |    |  |  |  | |  _____|\n");

// quinta linha
printf("   |   |    |  | | |_____ \t");
printf("   |   |    |  |  |  | | |_____ \t");
printf("   |   |    |  |__|  | | |_____ \n");

// sexta linha
printf("   |___|    |__| |_______|\t");
printf("   |___|    |__|  |__| |_______|\t");
printf("   |___|    |________| |_______|\n");
printf("\n");

}

void initTable(void) {
	int counter;

	for (counter = 0; counter <= 8; counter++) {
		tablePositions[counter] = 0;
	}
}

void twoPlayersGame(void) {
	int counter;

	// procedimento para iniciar a tabela do jogo
	initTable();

	receiveName();
	
	for (counter = 0; counter <= 8; counter++) {
		
		do {
		
			system("cls");
			printf("\nEstado atual da tabela\n");
			printTable(symbolsOnMove[0], symbolsOnMove[1]);
			printf("\nPosicoes da tabela\n");
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

	// exibe o estatus da partida toda.
	gameStatus();

	printf("\n\nPressione qualquer tecla para continuar...");
	getchar();

}

// procedure to receive the players name.
void receiveName(void) {
	
	printMenu();

	printf("\tDigite o nome do primeiro jogador: ");
	scanf("%s", player1);
	getchar();
	printf("\tDigite o nome do segundo jogador: ");
	scanf("%s", player2);
	getchar();
	
}

// function to return which player will play, this function return the player name.
char * printNamePlayer() {

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
void printTable(char symbolPlayerOne, char symbolPlayerTwo) {
	
	int counter;
	
	printf("\n");
	
	for (counter = 0; counter <= 8; counter++) {
		
		switch (tablePositions[counter]) {
			case 0:
				printf("|   ");
				break;
			case 1:
				printf("| %c ", symbolPlayerOne);
				break;
			case 2:
				printf("| %c ", symbolPlayerTwo);
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
	printTable(symbolsOnMove[0], symbolsOnMove[1]);
	
	if (drawnCase() == 1) {
		printf("\n\aOcorreu um empate empate!\n");
	} else {	
		printf("\n\a%s venceu o jogo!", printNamePlayer());
		matchesHistoric[playerTurn] += 1; // For sum in matches historic
	}

	
}

void startGame(void) {
	system("cls");
	system("color 0e");
}

void endGame(void) {
	system("cls");
	system("color 07");
	system("color 07");
}

/*

	printf(" _________   __   _______ ");
	printf("|         | |  | |  _____|");
	printf("|__     __| |  | | |      ");
	printf("   |   |    |  | | |      ");
	printf("   |   |    |  | | |_____ ");
	printf("   |___|    |__| |_______|");

	printf(" _________   ________   _______ ");
	printf("|         | |   __   | |  _____|");
	printf("|__     __| |  |  |  | | |      ");
	printf("   |   |    |  |__|  | | |      ");
	printf("   |   |    |  |  |  | | |_____ ");
	printf("   |___|    |__|  |__| |_______|");

	printf(" _________   ________   _______ ");
	printf("|         | |   __   | |  _____|");
	printf("|__     __| |  |  |  | | |_____ ");
	printf("   |   |    |  |  |  | |  _____|");
	printf("   |   |    |  |__|  | | |_____ ");
	printf("   |___|    |________| |_______|");

*/
