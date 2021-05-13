#ifndef GAME_STATE_H
#define GAME_STATE_H

enum TurnDirection {RIGHT, LEFT};

class GameState
{
    
    public:
    
    int numPlayers;
    
    int currentPlayerIndex;
    
    int numCardsToPlay;
    
    int numCardsToDraw;
    
    TurnDirection turnDirection;
    
    GameState(int n);
    
    void nextTurn();
    
    bool skipTurn = false;
    
};

#endif