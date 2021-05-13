#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "game_state.h"
#include "card.h"



void clearTerminal()
{
    
    for(int i = 0; i < 100; i++)
    {
        
        std::cout << std::endl;
        
    }
    
}

void buildDeck(std::vector<Card*> &deck)
{
    
    // Create Number Cards
    for(int c = RED; c < NUM_COLORS; c++)
    {
        
        for(int n = 0; n < WILD_CARDS; n++)
        {
            
            Card* temp = new NumberCard((Color)c, n);
            
            deck.push_back(temp);
            
            deck.push_back(temp);
            
            /*for(int n = 10; n < WILD_CARDS; n++)
            {
                Card* temp = new NumberCard((Color)c, n);
                
                deck.push_back(temp);
                
                //deck.push_back(temp);
            }*/
            
        }
        
        
    }
}

void shuffleDeck(std::vector<Card*> &deck)
{
    
    for(int i = 0; i < 1000; i++)
    {
        
        int idx1 = rand() % deck.size();
        int idx2 = rand() % deck.size();
        
        Card* temp = deck.at(idx1);
        
        deck.at(idx1) = deck.at(idx2);
        deck.at(idx2) = temp;
    }
    
}

void drawCards(std::vector<Card*> &deck, std::vector<Card*> &target, int numToDraw)
{
    
    for(int i = 0; i < numToDraw; i++)
    {
        
        if(deck.size() > 0)
        {
            
            target.push_back(deck.at(deck.size() - 1));
            deck.pop_back();
            
        } else {
            
            std::cout << "WARNING: Deck out of cards" << std::endl;
            
        }
        
    }
    
}

void populateHands(std::vector<Card*> &deck, std::vector<std::vector<Card*>> &hands)
{
    
    for(int i = 0; i < hands.size(); i++)
    {
        
        drawCards(deck, hands.at(i), 7);
        
    }
    
}

void renderHand(std::vector<Card*> hand)
{
    
    if(hand.size() > 0)
    {
        
        for(int i = 0; i <= 7; i++)
        {
            
            for(int j = 0; j < hand.size(); j++)
            {
                
                std::cout << hand.at(j)->render(i) << " ";
                
            }
            
            std::cout << std::endl;
            
        }
        
    } else {
        
        for(int i = 0; i <= 7; i++)
        {
            
            std::cout << std::endl;
            
        }
        
    }
    
}

void renderDiscard(std::vector<Card*> discard)
{
    
    for(int i = 0; i <= 7; i++)
    {
        
        std::cout << discard.at(discard.size() - 1)->render(i) << std::endl;
        
    }
    
}

void takeTurn(std::vector<Card*> &deck, std::vector<Card*> &hand, std::vector<Card*> &discard, GameState &gameState)
{
    
    clearTerminal();
    
    renderDiscard(discard);
    
    std::cout << "Player " << gameState.currentPlayerIndex << "'s turn." << std::endl;
    
    // TODO: Draw cards if necessary (draw 2 card)
    drawCards(deck, hand, gameState.numCardsToDraw);
    
    gameState.numCardsToDraw = 0;
    
    // reset cards to draw back to 0
    renderHand(hand);
    
    // loop for number of cards to play (0 if previously played card was a "skip" or "draw 2")
    for(int j = 0; j < gameState.numCardsToPlay; j++)
    {
        
        if(!gameState.skipTurn)
        {
            
            // Collect user input
            std::cout << "What would you like to do?" << std::endl;
            
            int i;
            
            for(i = 0; i < hand.size(); i++)
            {
                
                std::cout << i << ": Play Card" << std::endl;
                
            }  
            
            std::cout << i << ": Draw a Card" << std::endl;
            
            int input;
            
            std::cin >> input;
            
            // Evaluate user input
            if(input < i)
            {
                
                // Play card at index input
                if(hand.at(input)->play(discard.at(discard.size()-1), gameState))
                {
                    
                    Card* temp;
                    
                    temp = hand.at(input);
                    
                    discard.push_back(temp);
                    
                    hand.erase(hand.begin() + input);
                    
                    // Remove card in hand at position "input"
                    
                    
                } else {
                    
                    std::cout << "Improper choice" << std::endl;
                    
                    takeTurn(deck, hand, discard, gameState);
                    
                    return;
                }
            
            }else if(input == i){
                
                drawCards(deck, hand, 1);
                
            }    
        
        }else{
            
            gameState.skipTurn = false;
            
        }
        
        // update variables for next turn
        gameState.nextTurn();
        
    }
    
}

int main()
{
    
    srand(time(0));
    
    int inputNum;
    std::cout << "Pick the number of Players: ";
    std::cin >> inputNum;
    
    const int NUM_PLAYERS = inputNum;
    GameState gameState(NUM_PLAYERS);
    
    std::vector<Card*> deck;
    std::vector<Card*> discard;
    
    std::vector<std::vector<Card*>> hands(NUM_PLAYERS);
    
    buildDeck(deck);
    shuffleDeck(deck);
    populateHands(deck, hands);
    drawCards(deck, discard, 1);
    
    while(1 /* TODO: Check for winner (no cards in hand)*/)
    {
        
        takeTurn(deck, hands.at(gameState.currentPlayerIndex), discard, gameState);
        
    }
    
    return 0;
    
}

