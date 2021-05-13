#include "card.h"

Color Card::getColor() const {
    return color;
}

int Card::getNumber() const {
    return number;
}

void Card::setColor(Color c) {
    color = c;
}

void Card::setNumber(int n) {
    number = n;
}

void Card::setWildC(WildC w) {
    wildc = w;
}

NumberCard::NumberCard(Color c, int n) {
    setColor(c);
    setNumber(n);
}

/*NumberCard::NumberCard(Color c, int n, WildC w) {
    setColor(c);
    setNumber(n);
    setWildC(w);
}*/

NumberCard::NumberCard(WildC w, int n)  {
    setWildC(w);
    setNumber(n);
}

std::string NumberCard::render(int line) const {
    
    std::stringstream ss;
    
    switch(line) 
    {
        case 0: return ".___________.";
        
        case 1: return "|           |";
        
        case 2:
            if(number > 9)
            {
                switch(number)
                {
                    case 10:
                        return "| +2        |";
                        break;
                    case 11:
                        return "| SKIP      |";
                        break;
                    case 12:
                        return "| R      <- |";
                        break;
                    case 13:
                        return "| RGBY      |";
                        break;
                    default:
                        return "|           |";
                        break;
                }
            } else {
                ss << "| " << number << "         |";
                return ss.str();
                break;
            }
            
            /*ss << "| " << number << "         |";
            return ss.str();
            break;*/
            
        case 3: return "|           |";
            
        case 4:
            switch(color)
            {
                case RED:
                    return "|    RED    |";
                    break;
                case BLUE:
                    return "|    BLUE   |";
                    break;
                case GREEN:
                    return "|   GREEN   |";
                    break;
                case YELLOW:
                    return "|  YELLOW   |";
                    break;
                default:
                    return "|           |";
                    break;
                break;
            }
        /*case 3:
            ss << "|     " << number << "     |";
            return ss.str();
            break;*/
            
        case 5: return "|           |";
            
        case 6:
            
            if(number > 9)
            {
                switch(number)
                {
                    case 10:
                        return "|        +2 |";
                        break;
                    case 11:
                        return "|      SKIP |";
                        break;
                    case 12:
                        return "| ->      R |";
                        break;
                    case 13:
                        return "|      RGBY |";
                        break;
                    default:
                        return "|           |";
                        break;
                }
            } else {
                ss << "|         " << number << " |";
                return ss.str();
                break;
            }
            
            /*ss << "|         " << number << " |";
            return ss.str();
            break;*/
            
        case 7: return "|___________|";
            
        default:
            return " ";
            
    }
    
}

bool NumberCard::play(Card* discard, GameState &gameState) {
    
    if(color == discard->getColor() || number == discard->getNumber())
    {
        
        return true;
        
    } else {
        
        return false;
        
    }
    
}