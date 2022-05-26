#pragma once
#include <string>
using namespace std;
class Team{
    public:
        string name;
        double talent = 0;
        int wins = 0;
        int losses = 0;
        int positive_points = 0;
        int negative_points = 0;
        int curr_win_strike = 0;
        int curr_loss_strike = 0;
        int points_in_curr_game = 0;
        Team(const string & name) : name(name){};
        void give_talent();
        
};  