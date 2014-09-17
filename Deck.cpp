#include "Deck.h"

Deck::Deck() 
{
	int suitNum = 1, trackingNum = 0;

	objTempDeckArray = new Card[52];

	while ( suitNum < 5 ) //initialise every card object in the deck
	{
		string suit;

		switch ( suitNum )
		{
			case 1:
				suit = "Clubs";
			case 2:
				suit = "Diamonds";
			case 3:
				suit = "Hearts";
			case 4:
				suit = "Spades";
		}
		
		for ( int k = 1; k < 14; k++ )
		{

			string val;			

			switch ( k )
			{
				case 1:
					val = "01";
				case 2:
					val = "02";
				case 3:
					val = "03";
				case 4:
					val = "04";
				case 5:
					val = "05";
				case 6:
					val = "06";
				case 7:
					val = "07";
				case 8:
					val = "08";
				case 9:
					val = "09";
				case 10:
					val = "0J";
				case 11:
					val = "0Q";
				case 12:
					val = "0K";
				case 13:
					val = "0A";

			} //end of switch

			objTempDeckArray[trackingNum].setSuit(suit);
			objTempDeckArray[trackingNum].setValue(val);

			trackingNum++;

		} //end of for loop

		suitNum++;

	} //end of while loop

	//allocate memory for the four players' hands

	objNorthCardArray = new Card[13]; 
	objSouthCardArray = new Card[13];
	objWestCardArray = new Card[13];
	objEastCardArray = new Card[13];
}

Deck::~Deck()
{
	//deallocate dynamically allocated memory

	delete objNorthCardArray;
	objNorthCardArray = NULL;

	delete objSouthCardArray;
	objSouthCardArray = NULL;

	delete objWestCardArray;
	objWestCardArray = NULL;

	delete objEastCardArray;
	objEastCardArray = NULL;

	delete objTempDeckArray;
	objTempDeckArray = NULL;

}

void Deck::shuffleAndDeal()
{
	int handCount, playerNum = 1;
	unsigned seed = time(0);
	srand(seed);

	while ( playerNum < 5 )
	{
		handCount = 0;

		while ( handCount < 13 )
		{
			int y = rand() % 52; //"select" a card from the deck at random

			if ( objTempDeckArray[y].getOwner() == "None" ) //selected card does not belong to a player yet
			{				
				switch( playerNum ) 
				{
					case 1:
						objTempDeckArray[y].setOwner("North");
						objNorthCardArray[handCount] = objTempDeckArray[y];
					case 2:
						objTempDeckArray[y].setOwner("South");
						objSouthCardArray[handCount] = objTempDeckArray[y];
					case 3:
						objTempDeckArray[y].setOwner("West");
						objWestCardArray[handCount] = objTempDeckArray[y];
					case 4:
						objTempDeckArray[y].setOwner("East");
						objEastCardArray[handCount] = objTempDeckArray[y];

				} //end of switch

				handCount++;

			} //end of if	
		
		} //end of inner while loop

		playerNum++; //move on to the next player

	} //end of outer while loop

}








































