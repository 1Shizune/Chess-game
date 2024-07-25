#include<iostream>
#include<vector>
#include <ctime> // for time
#include <algorithm> // for random_shuffle
using namespace std;
int main()
{

enum Suit{Clubs, Diamonds, Heart, Spades, NUM_SUIT};
enum CardsValue{Ace=1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, NUM_VALUE};

//int FirstHand[5] = {};
//int SecondHand[5] = {};

struct Card //Structs group multiple related variables into a single thing
{
	Suit suit;
	CardsValue value; 
};

	vector<Card> deck; //Vector takes in Card structs to fill up a deck
	for(int suit=0; suit < NUM_SUIT; ++suit) //For loops takes a single suit, fills up 13 cards and moves the next suit, until all 4 suits are used and filled
	{
	
		for(int value = 0; value < NUM_VALUE; ++value) //For every suit fill up 13 cards
		{		
			Card card; //Create variable card from the struct type Card
			card.suit = static_cast<Suit>(suit); //Static_cast changes the type of a variable <changeDestination>(target)
			card.value = static_cast<CardsValue>(value); //Change the int used in the for loop, named value, to a CardsValue type, defined in the enums
			deck.push_back(card); //Push the newly created card to the back of the deck
		}
		
	}
	
	srand(static_cast<unsigned int>(time(nullptr))); //ensure random picks everytime program is ran		
 	random_shuffle(deck.begin(),deck.end());
 
 		vector<Card> Hand1;
 		vector<Card> Hand2;
 		for(int i =0; i < 5; ++i)
		 {
		 	Hand1.push_back(deck[i]);	
		 	Hand2.push_back(deck[i+5]); //acces cards from index 6 and onwards, since the first five cards are given to hand1
		 }
 
 			const char* suits[] = {"Clubs", "Diamonds", "Heart", "Spades"}; //char* = array of strings, without the * = too many initializers error
 			const char* values[] = {"ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING"};
 		

			 cout << "The first hand has the cards: " << endl;
			 for(const auto& card : Hand1) 
			 {
    			cout << values[card.value - 1] << " of " << suits[card.suit] << endl;
			}

				int Hand1Value=0; 
				for(int i=0; i<5; ++i) //iterate through the cards inside of Hand1 and add the value of all the cards into a single int variable
				{
				
					Hand1Value += Hand1[i].value;
				
				}
				
				int Hand2Value=0;
				for(int i=0; i<5; ++i)
				{
				
					Hand2Value += Hand2[i].value;
				
				}
				
				
				
				 cout << endl;
				 cout << "The second hand has the cards: " << endl;
				for(const auto& card : Hand2) 
				{
    				cout << values[card.value - 1] << " of " << suits[card.suit] << endl;
				}
			 
			 		cout << endl;
 					if(Hand1Value > Hand2Value)
 					{
						cout << "Player 1 Wins!" << endl; 
					}
 						else if(Hand1Value < Hand2Value)
 						{
							cout << "Player 2 Wins!" << endl; 
						}
 							else
							 {
							 	cout << "The game is a tie!" << endl;
							 }
 
 
 



}

