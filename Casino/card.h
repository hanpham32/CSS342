#ifndef CARD_H_
#define CARD_H_
#include <string>
#include <iostream>
using namespace std;

const int kLargestValue = 13;
const int kNumSuits = 4;
enum Suit {kHeart, kDiamond, kClub, kSpade};
const string kSuits[kNumSuits] = {"heart", "diamond", "club", "spade"};

class Card
{
    public:
        // Constructors
        Card();
        Card(int val, Suit suit);

        //getters-setters
        int value() const;
        Suit suit() const;

        //Operator Overloads
        friend ostream& operator << (ostream& stream, const Card& card);
        bool operator==(const Card& card) const;
        bool operator!=(const Card& card) const;

    private:
        int value_;
        Suit suit_;
};
#endif