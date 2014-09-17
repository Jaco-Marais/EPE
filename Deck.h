#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <cstdlib>
#include <ctime>
#include <QDebug>

class Deck
{

	private:

		Card *objNorthCardArray; //points to North's hand
		Card *objSouthCardArray; //points to South's hand
		Card *objWestCardArray;  //points to West's hand
		Card *objEastCardArray;	 //points to East's hand

		Card *objTempDeckArray;	 //points to full deck of cards

	public:

		Deck(); 		     //constructor
		~Deck();		     //destructor
		void shuffleAndDeal();	     //"shuffle" cards and deal to players
		bool validateCard( Card& );  //check if card selection is valid
		Card* getCardArray(string);  //return the hand of a specific player
};

#endif
