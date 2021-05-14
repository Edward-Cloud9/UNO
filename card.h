#ifndef CARD_H
#define CARD_H

#include <sstream>

#include "game_state.h"

enum Color{RED, BLUE, GREEN, YELLOW, NUM_COLORS};

enum WildC{PLUS2 = 10, SKIP = 11, REVERSE = 12, WILD = 13, WILD_CARDS};

class Card
{
    
    protected:
    
    Color color;
    
    WildC wildc;
    
    int number;
    
    public:
    
    Color getColor() const;
    
    int getNumber() const;
    
    int getWildCard() const;
    
    void setColor(Color c);
    
    void setNumber(int n);
    
    void setWildC(WildC w);
    
    virtual std::string render(int line) const = 0;
    virtual bool play(Card* discard, GameState& gameState) = 0;
    
};

class NumberCard : public Card
{
    
    public:
    
    NumberCard(Color c, int n);
    
    //NumberCard(Color c, int n, WildC w);
    //NumberCard(WildC w, int m);
    
    
    std::string render(int) const;
    
    bool play(Card*, GameState&);
    
};

class WildCard : public Card
{
    public:
    
    WildCard(Color c, WildC w);
    
    std::string render(int) const;
    
    bool play(Card*, GameState&);
    
};



#endif