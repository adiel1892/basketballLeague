#pragma once
#include <string>

class Team{
    public:
        std::string name;
        double talent = rand();
        int wins = 0;
        int losses = 0;
        int positive_points = 0;
        int negative_points = 0;
        int curr_win_strike = 0;
        int curr_loss_strike = 0;
        int points_in_curr_game = 0;
        Team(const std::string & name) : name(name){};

};  