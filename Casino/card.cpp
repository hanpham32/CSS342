#include "card.h"
#include <string>

Card::Card() : value_(1), suit_(kSpade)
{
}

Card::Card(int value, Suit suit) : value_(value), suit_(suit)
{
    if ((value < 1) || (value > kLargestValue))
    {
        value_ = 1;
    }
}

Suit Card::suit() const
{
    return suit_;
}

bool Card::operator==(const Card& rhs) const
{
    return ((value_ == rhs.value_) && (suit_ == rhs.suit_));
}

bool Card::operator!=(const Card& rhs) const
{
    return !(*this == rhs);
}

int Card::value() const
{
    return value_;
}

ostream& operator<<(ostream& stream, const Card& card)
{
    string card_value, card_suit;
    card_suit = kSuits[card.suit()];

    switch (card.value())
    {
        case 1:
            card_value = "ace";
            break;
        case 11:
            card_value = "jack";
            break;
        case 12:
            card_value = "queen";
            break;
        case 13:
            card_value = "king";
            break;
        default:
            card_value = to_string(card.value());
    }
    stream << card_value << " of " << card_suit;
    return stream;
}