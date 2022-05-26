#pragma once
#include <string>

class Team{
    public:
        string name;
        double talent;
        int wins;
        int losses;
        int positive_points;
        int negative_points;
        int curr_win_strike;
        int curr_loss_strike;
        Team(const string & name);

};  