#pragma once
#include "Team.hpp"

class Game{   
    public:
    Team *home;
    Team *away;
    Game(Team & home ,Team & away);
    void points_in_game();
    void winner_losser();   

};