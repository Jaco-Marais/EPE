#include "Card.h"

using namespace std;

    Card::Card()
    {
        setOwner("None");
        setIsPlayed(false);
    }

//    const Card operator=(  Card &right)
//	{
//		suit = right.getSuit();
//		value = right.getValue();
//		owner = right.getOwner();
//		isPlayed = right.getIsPlayed();

//		return *this;
//	}

    void Card::setSuit(string suitVal )
    {
        suit = suitVal;
    }

    string Card::getSuit() const
    {
        return suit;
    }

    void Card::setValue(string cardVal)
    {
        cardValue = cardVal;
    }

    string Card::getValue() const
    {
        return cardValue;
    }

    void Card::setOwner(string ownerVal)
    {
        ownerPosition = ownerVal;
    }

    string Card::getOwner() const
    {
        return ownerPosition;
    }

    void Card::setIsPlayed(bool status)
    {
        isPlayed = status;
    }

    bool Card::getIsPlayed() const
    {
        return isPlayed;
    }















