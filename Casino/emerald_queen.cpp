#include <iostream>
#include "deck.h"
using namespace std;

int main()
{
    Deck blackjack;

    blackjack.Shuffle();
    blackjack.Cut();
    Card hole_card = blackjack.DealCard();
    Card up_card = blackjack.DealCard();
    cout << hole_card << " , " << up_card << endl;
    int score = hole_card.value() + up_card.value();
    if (score == 21)
    {
        cout << "BLACKJACK!!" << endl;
    } else 
    {
        cout << "Meh" << endl;
    }
    return 0;
}