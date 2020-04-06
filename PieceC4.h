// Alex Chang, 400268761
// PieceC4.h

#ifndef PIECEC4_H
#define PIECEC4_H

#include <iostream>

class PieceC4 {
private:
	int piece;
public:
	PieceC4(); // Default Constructor

	// Accessor Methods
	int getPiece() const;

	// Mutator Methods
	void setPiece(int p);

};
#endif
