#include "Header.h"
#include "Player.h"
#include "Boards.h"

int main() {
	
	string nameX, nameO;
	getNames(nameX, nameO);

	Player player1(nameX, 'X'), player2(nameO, 'O');

	Boards board;

	board.printBoard();

	
	
	for (int i = 0; i < 8; i++) {
		//player1 turn
		
		int movePlayer1;

		while (1) {
			// asks player what move they want to make 
			// >>> if taken then asks again till valid move is given
			movePlayer1 = player1.getMove();
			if (board.checkPosition(movePlayer1)) {
				//checks weather if move was allowed >> if so then it breaks the loop
				break;
			}
			cout << "You have Played in the taken spot, try a different spot!!\n\n";
		}
		board.setPosition(movePlayer1, player1.getIcon());
		board.printBoard();

		board.printLegalMoves();

		if (board.winnerIs() != 'z') {
			cout << player1.getName() << " Won, congratz!!" << endl;
			break;
		}
		
		//player 2
		int movePlayer2;

		while (1) {
			// asks player what move they want to make 
			// >>> if taken then asks again till valid move is given
			movePlayer2 = player2.getMove();
			if (board.checkPosition(movePlayer2)) {
				break;
			}
			cout << "You have Played in the taken spot, try a different spot!!\n\n";
		}
		board.setPosition(movePlayer2, player2.getIcon());
		board.printBoard();

		board.printLegalMoves();

		if (board.winnerIs() != 'z') {
			cout << player2.getName() << " Won, congratz!!" << endl;
			break;
		}
		

	}
	
	return 0;
}

