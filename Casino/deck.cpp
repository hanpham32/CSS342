#include "deck.h"

Deck::Deck() : count_(kCardsInDeck)
{
    int i = 0;
    for (int val = 1; val <= kLargestValue; val++)
    {
        for (int s = 0; s <= kNumSuits; s++)
        {
            cards_[i] = Card(val, (Suit) s);
            i++;
        }
    }

    //randomly setting seed which is used by the Cut function
    srand(time(0));
}

int Deck::CountCardRemaining() const
{
    return count_;
}

bool Deck::isEmpty() const
{
    return (count_ == 0);
}

bool Deck::isComplete() const
{
    return (count_ == kCardsInDeck);
}

Card Deck::Peek() const
{
    return (cards_[0]);
}

//Remove top of card and shift all cards up in array
Card Deck::DealCard()
{
    Card card = cards_[0];
    for (int i=0; i < count_ - 1; i++)
    {
        cards_[i] = cards_[i+1];
    }
    count_--;
    return card;
}

//Return card to bottom of deck
bool Deck::ReturnCard(const Card& card)
{
    if (Contains(card))
    {
        return false;
    }
    cards_[count_] = card;
    count_++;
    return true;
}

bool Deck::Contains(const Card& card) const
{
    for (int i=0; i<count_; i++)
    {
        if (cards_[i] == card)
        {
            return true;
        }
    }
    return false;
}

//Simple shuffle methods
void Deck::Shuffle()
{
    Deck copy_deck = *this;
    //Loop through copy of deck randomly choosing card at a time
    int cards_left = count_;
    for (int i=0; i<count_; i++)
    {
        int selected = rand() % cards_left;
        cards_[i] = copy_deck.cards_[selected];
        for (int j=selected; j< count_ - 1; j++)
        {
            copy_deck.cards_[j] = copy_deck.cards_[j+1];
        }
        cards_left--;
    }
}

void Deck::Cut()
{
    Deck copy_deck = *this;
    int cut_location = rand() % count_;
    for (int i=0; i<count_; i++)
    {
        cards_[i] = copy_deck.cards_[(cut_location + i) % count_];
    }
}

ostream& operator<<(ostream& stream, const Deck& deck)
{
    for (int i=0; i<deck.count_; i++)
    {
        stream << deck.cards_[i] << endl;
    }
    return stream;
}