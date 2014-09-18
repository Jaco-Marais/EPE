#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>
#include <QDebug>
using namespace std;

class Card
{

    private:

        string suit; //contains the suit to which the card belongs
        string cardValue; //contains the value of the card
        string ownerPosition; //contains seat position of the card's owner
        bool isPlayed; //keeps track of whether card has been played or not during the current deal

    public:
        Card(); //constructor
//		const Card operator=( const Card &right); //used to copy one card object's data to another

        // moet dalk ook die << operator overload om Card se data maklik uit te print

        void setSuit(string); //sets card's suit
        string getSuit() const; //returns card's suit

        void setValue(string); //sets card's value
        string getValue() const; //return card's value

        void setOwner(string); //set card's owner's position
        string getOwner() const; //return card's owner's position

        void setIsPlayed(bool); //set card's played status
        bool getIsPlayed() const; //return card's played status

};

#endif
