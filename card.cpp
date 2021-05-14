#include "card.h"

Color Card::getColor() const {
    return color;
}

int Card::getNumber() const {
    return number;
}

int Card::getWildCard() const {
    return wildc;
}

int Card::setColorbyWild(int x) const {
    
    if(x = 1)
    {
        return Color(1);
    }
    else if(x = 2)
    {
        return Color(2);
    }
    else if(x = 3)
    {
        return Color(3);
    }
    else if(x = 4)
    {
        return Color(4);
    }
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

WildCard::WildCard(Color c, WildC w)  {
    setColor(c);
    setWildC(w);
    //setNumber(n);
}

std::string NumberCard::render(int line) const {
    
    std::stringstream ss;
    
    switch(line) 
    {
        case 0: return ".___________.";
        
        case 1: return "|           |";
        
        case 2:
            /*if(number > 9)
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
            }*/
            
            ss << "| " << number << "         |";
            return ss.str();
            break;
            
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
            
            /*if(number > 9)
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
            }*/
            
            ss << "|         " << number << " |";
            return ss.str();
            break;
            
        case 7: return "|___________|";
            
        default:
            return " ";
            
    }
    
}


std::string WildCard::render(int line) const {
    
    std::stringstream ss;
    
    switch(line) 
    {
        case 0: return ".___________.";
        
        case 1: return "|           |";
        
        case 2:
            
            switch(wildc)
            {
                case 10:
                    return "| +2        |";
                    break;
                case 11:
                    return "| SKIP      |";
                    break;
                case 12:
                    return "| R     <-- |";
                    break;
                case 13:
                    return "| WILD      |";
                    break;
                default:
                    return "|           |";
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
            
            switch(wildc)
            {
                case 10:
                    return "|        +2 |";
                    break;
                case 11:
                    return "|      SKIP |";
                    break;
                case 12:
                    return "| -->     R |";
                    break;
                case 13:
                    return "|      WILD |";
                    break;
                default:
                    return "|           |";
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

bool WildCard::play(Card* discard, GameState &gameState) {
    
    if(color == discard->getColor() || wildc == discard->getWildCard())
    {
        
        return true;
        
    } else {
        
        return false;
        
    }
}
    