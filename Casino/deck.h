//Can deal and return cards to the deck
//Also can mix up cards using a cut/shuffle function
#ifndef DECK_H_
#define DECK_H_
#include "card.h"

const int kCardsInDeck = kLargestValue * kNumSuits;

class Deck
{
    public:
        Deck();

        //utility function
        int CountCardRemaining() const;
        bool isEmpty() const;
        bool isComplete() const;

        //show top card
        Card Peek() const;

        //deal from top and return to bottom of deck
        Card DealCard();
        bool ReturnCard(const Card& card);
        bool Contains(const Card& card) const;

        //mix up deck
        void Shuffle();
        void Cut();

        //Overloads
        friend ostream& operator <<(ostream& stream, const Deck& deck);

    private:
        Card cards_[kCardsInDeck];
        int count_;
};

#endif
