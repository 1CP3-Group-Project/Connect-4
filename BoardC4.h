// Alex Chang, 400268761
// BoardC4.h

#ifndef BOARDC4_H
#define BOARDC4_H

#include "gameClass.h"
#include "PieceC4.h"
#include <string>

const int SIZEX = 7;
const int SIZEY = 6;

class BoardC4 : public gameClass {
private:
	PieceC4 board[SIZEY][SIZEX];
	const std::string label{ 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
	int loop; // Loop for game
	bool win; // Lock triggered when a win is achieved
	int turn; // Player turn
	char letter; // Player's entered letter
	int moves; // Total amount of moves made (to trigger a tie)
public:
	BoardC4(); // Default Constructor

	// Accessor Methods
	bool getWin() const { return win; }
	char getLetter() const { return letter; }
	int getTurn() const { return turn; }
	int getMoves() const { return moves; }

	// Mutator Methods
	void setLetter(char l) { letter = l; }
	void setTurn(int t) { turn = t; }
	void setWin(bool w) { win = w; }

	// Member Functions
	void checkWinCondition();
	void setMoves();
	void printBoard() const;
	void placePiece();
	void setPiece();
	void setPlayersName();

	// Virtual Methods
	virtual void playGame() const;
	virtual void saveGame() const;
};
#endif
