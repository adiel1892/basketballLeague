#pragma once
#include "Team.hpp"
constexpr int min_away_points = 50;
constexpr int min_home_points = 55;
constexpr int max_points = 100;
constexpr int mul_talent = 10;


class Game{   
    public:
    Team *home;
    Team *away;
    Game(Team & home ,Team & away) : home(&home) , away(&away){};
    void points_in_game()const;
    void winner_losser()const; 
    void print_game()const;  
    void start_game()const;

};