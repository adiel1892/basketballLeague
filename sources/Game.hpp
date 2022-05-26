#pragma once
#include "Team.hpp"

class Game{   
    public:
    Team *home;
    Team *away;
    Game(const Team & home , const Team & away);
    
    void winner_losser();   

};