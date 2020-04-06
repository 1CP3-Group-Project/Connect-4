// Alex Chang, 400268761
// BoardC4.cpp

#include "BoardC4.h"

// Default Constructor
BoardC4::BoardC4() {
	loop = 0;
	win = false;
	turn = 1;
	letter = 'N';
	moves = 0;
}

// Member Functions
void BoardC4::checkWinCondition() {
	int counter = 0;
	if (this->getTurn() == 1) {
		// Horizontal Check
		for (int i = 0; i < SIZEY; i++) {
			for (int f = 0; f < SIZEX; f++) {
				if (this->board[i][f].getPiece() == 2)
					counter++;
				else
					counter = 0;
				if (counter >= 4) {
					std::cout << this->getPlayerTwo() << " Wins!\n";
					this->setWin(true);
				}
			}
		}
		// Vertical Check
		for (int i = 0; i < SIZEX; i++) {
			for (int f = 0; f < SIZEY; f++) {
				if (this->board[f][i].getPiece() == 2)
					counter++;
				else
					counter = 0;
				if (counter >= 4) {
					std::cout << this->getPlayerTwo() << " Wins!\n";
					this->setWin(true);
				}
			}
		}
		// Diagonal Check (left to right)
		for (int i = 0; i < SIZEY; i++) {
			for (int f = 0; f < SIZEX; f++) {
				if (this->board[i][f].getPiece() == 2) {
					counter++;
					if (this->board[i + 1][f - 1].getPiece() == 2) {
						counter++;
						if (this->board[i + 2][f - 2].getPiece() == 2) {
							counter++;
							if (this->board[i + 3][f - 3].getPiece() == 2)
								counter++;
							else
								counter = 0;
						}
						else
							counter = 0;
					}
					else
						counter = 0;
				}
				else
					counter = 0;
				if (counter >= 4) {
					std::cout << this->getPlayerTwo() << " Wins!\n";
					this->setWin(true);
				}
			}
		}
		// Diagonal Check (right to left)
		for (int i = 0; i < SIZEY; i++) {
			for (int f = 0; f < SIZEX; f++) {
				if (this->board[i][f].getPiece() == 2) {
					counter++;
					if (this->board[i + 1][f + 1].getPiece() == 2) {
						counter++;
						if (this->board[i + 2][f + 2].getPiece() == 2) {
							counter++;
							if (this->board[i + 3][f + 3].getPiece() == 2)
								counter++;
							else
								counter = 0;
						}
						else
							counter = 0;
					}
					else
						counter = 0;
				}
				else
					counter = 0;
				if (counter >= 4) {
					std::cout << this->getPlayerTwo() << " Wins!\n";
					this->setWin(true);
				}
			}
		}
	}
	if (this->getTurn() == 2) {
		// Horizontal Check
		for (int i = 0; i < SIZEY; i++) {
			for (int f = 0; f < SIZEX; f++) {
				if (this->board[i][f].getPiece() == 1)
					counter++;
				else
					counter = 0;
				if (counter >= 4) {
					std::cout << this->getPlayerOne() << " Wins!\n";
					this->setWin(true);
				}
			}
		}
		// Vertical Check
		for (int i = 0; i < SIZEX; i++) {
			for (int f = 0; f < SIZEY; f++) {
				if (this->board[f][i].getPiece() == 1)
					counter++;
				else
					counter = 0;
				if (counter >= 4) {
					std::cout << this->getPlayerOne() << " Wins!\n";
					this->setWin(true);
				}
			}
		}
		// Diagonal Check (left to right)
		for (int i = 0; i < SIZEY; i++) {
			for (int f = 0; f < SIZEX; f++) {
				if (this->board[i][f].getPiece() == 1) {
					counter++;
					if (this->board[i + 1][f - 1].getPiece() == 1) {
						counter++;
						if (this->board[i + 2][f - 2].getPiece() == 1) {
							counter++;
							if (this->board[i + 3][f - 3].getPiece() == 1)
								counter++;
							else
								counter = 0;
						}
						else
							counter = 0;
					}
					else
						counter = 0;
				}
				else
					counter = 0;
				if (counter >= 4) {
					std::cout << this->getPlayerOne() << " Wins!\n";
					this->setWin(true);
				}
			}
		}
		// Diagonal Check (right to left)
		for (int i = 0; i < SIZEY; i++) {
			for (int f = 0; f < SIZEX; f++) {
				if (this->board[i][f].getPiece() == 1) {
					counter++;
					if (this->board[i + 1][f + 1].getPiece() == 1) {
						counter++;
						if (this->board[i + 2][f + 2].getPiece() == 1) {
							counter++;
							if (this->board[i + 3][f + 3].getPiece() == 1)
								counter++;
							else
								counter = 0;
						}
						else
							counter = 0;
					}
					else
						counter = 0;
				}
				else
					counter = 0;
				if (counter >= 4) {
					std::cout << this->getPlayerOne() << " Wins!\n";
					this->setWin(true);
				}
			}
		}
	}
}

void BoardC4::setMoves() {
	moves++;
}
void BoardC4::printBoard() const {
	std::cout << "~~~~~~ Board ~~~~~~\n";
	for (int i = 0; i < SIZEY; i++) {
		for (int f = 0; f < SIZEX; f++) {
			std::cout << this->board[i][f].getPiece() << "  ";
		}
		std::cout << "\n";
	}
	std::cout << "-------------------\n";
	for (int i = 0; i < SIZEX; i++) {
		std::cout << label[i] << "  ";
	}
	std::cout << "\n";
	std::cout << "===================\n";
}
void BoardC4::placePiece() {
	char temp = 'N';
	if (this->getTurn() == 1) {
		std::cout << this->getPlayerOne() << "'s turn! Enter a displayed character to drop a piece: ";
		std::cin >> temp;
		std::cout << "\n";
		this->setLetter(temp);
		this->setTurn(2);
	}
	else if (this->getTurn() == 2) {
		std::cout << this->getPlayerTwo() << "'s turn! Enter a displayed character to drop a piece: ";
		std::cin >> temp;
		std::cout << "\n";
		this->setLetter(temp);
		this->setTurn(1);
	}
}
void BoardC4::setPiece() {
	if (this->getLetter() == 'a') {
		if (this->board[0][0].getPiece() != 0) {
			std::cout << "Invalid character!\n";
			if (this->getTurn() == 2)
				this->setTurn(1);
			else if (this->getTurn() == 1)
				this->setTurn(2);
		}
		else {
			for (int i = 5; i > -1; i--) {
				if (this->board[i][0].getPiece() == 0) {
					if (this->getTurn() == 2) {
						this->board[i][0].setPiece(1);
						this->setMoves();
					}
					else if (this->getTurn() == 1) {
						this->board[i][0].setPiece(2);
						this->setMoves();
					}
					break;
				}
			}
		}
	}
	else if (this->getLetter() == 'b') {
		if (this->board[0][1].getPiece() != 0) {
			std::cout << "Invalid character!\n";
			if (this->getTurn() == 2)
				this->setTurn(1);
			else if (this->getTurn() == 1)
				this->setTurn(2);
		}
		else {
			for (int i = 5; i > -1; i--) {
				if (this->board[i][1].getPiece() == 0) {
					if (this->getTurn() == 2) {
						this->board[i][1].setPiece(1);
						this->setMoves();
					}
					else if (this->getTurn() == 1) {
						this->board[i][1].setPiece(2);
						this->setMoves();
					}
					break;
				}
			}
		}
	}
	else if (this->getLetter() == 'c') {
		if (this->board[0][2].getPiece() != 0) {
			std::cout << "Invalid character!\n";
			if (this->getTurn() == 2)
				this->setTurn(1);
			else if (this->getTurn() == 1)
				this->setTurn(2);
		}
		else {
			for (int i = 5; i > -1; i--) {
				if (this->board[i][2].getPiece() == 0) {
					if (this->getTurn() == 2) {
						this->board[i][2].setPiece(1);
						this->setMoves();
					}
					else if (this->getTurn() == 1) {
						this->board[i][2].setPiece(2);
						this->setMoves();
					}
					break;
				}
			}
		}
	}
	else if (this->getLetter() == 'd') {
		if (this->board[0][3].getPiece() != 0) {
			std::cout << "Invalid character!\n";
			if (this->getTurn() == 2)
				this->setTurn(1);
			else if (this->getTurn() == 1)
				this->setTurn(2);
		}
		else {
			for (int i = 5; i > -1; i--) {
				if (this->board[i][3].getPiece() == 0) {
					if (this->getTurn() == 2) {
						this->board[i][3].setPiece(1);
						this->setMoves();
					}
					else if (this->getTurn() == 1) {
						this->board[i][3].setPiece(2);
						this->setMoves();
					}
					break;
				}
			}
		}
	}
	else if (this->getLetter() == 'e') {
		if (this->board[0][4].getPiece() != 0) {
			std::cout << "Invalid character!\n";
			if (this->getTurn() == 2)
				this->setTurn(1);
			else if (this->getTurn() == 1)
				this->setTurn(2);
		}
		else {
			for (int i = 5; i > -1; i--) {
				if (this->board[i][4].getPiece() == 0) {
					if (this->getTurn() == 2) {
						this->board[i][4].setPiece(1);
						this->setMoves();
					}
					else if (this->getTurn() == 1) {
						this->board[i][4].setPiece(2);
						this->setMoves();
					}
					break;
				}
			}
		}
	}
	else if (this->getLetter() == 'f') {
		if (this->board[0][5].getPiece() != 0) {
			std::cout << "Invalid character!\n";
			if (this->getTurn() == 2)
				this->setTurn(1);
			else if (this->getTurn() == 1)
				this->setTurn(2);
		}
		else {
			for (int i = 5; i > -1; i--) {
				if (this->board[i][5].getPiece() == 0) {
					if (this->getTurn() == 2) {
						this->board[i][5].setPiece(1);
						this->setMoves();
					}
					else if (this->getTurn() == 1) {
						this->board[i][5].setPiece(2);
						this->setMoves();
					}
					break;
				}
			}
		}
	}
	else if (this->getLetter() == 'g') {
		if (this->board[0][6].getPiece() != 0) {
			std::cout << "Invalid character!\n";
			if (this->getTurn() == 2)
				this->setTurn(1);
			else if (this->getTurn() == 1)
				this->setTurn(2);
		}
		else {
			for (int i = 5; i > -1; i--) {
				if (this->board[i][6].getPiece() == 0) {
					if (this->getTurn() == 2) {
						this->board[i][6].setPiece(1);
						this->setMoves();
					}
					else if (this->getTurn() == 1) {
						this->board[i][6].setPiece(2);
						this->setMoves();
					}
					break;
				}
			}
		}
	}
	else {
		std::cout << "Invalid character!\n";
		if (this->getTurn() == 1)
			this->setTurn(2);
		else if (this->getTurn() == 2)
			this->setTurn(1);
	}
}
void BoardC4::setPlayersName() {
	std::string playerTemp;
	std::cout << "**NO SPACES ALLOWED**\n";
	std::cout << "Player 1 Name: ";
	std::cin >> playerTemp;
	this->setPlayerOne(playerTemp);

	std::cout << "Player 2 Name: ";
	std::cin >> playerTemp;
	this->setPlayerTwo(playerTemp);
	std::cout << "\n";
}

// Virtual Methods
void BoardC4::playGame() const {
	BoardC4 board;
	board.setPlayersName();
	while (board.loop != 1) {
		board.printBoard();
		board.placePiece();
		board.setPiece();
		board.checkWinCondition();
		if (board.getWin() == true) {
			board.printBoard();
			break;
		}
		else if (board.getMoves() == 42) {
			board.printBoard();
			std::cout << "Tie!\n";
			break;
		}
	}
}
void BoardC4::saveGame() const { } // Connect 4 doesn't require a save option
