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
        int longest_wins_strike = 0;
        int longest_losses_strike = 0;
        int diff_points = 0;
        Team(const string & name) : name(name){};
        void give_talent();
        void update_win_strike();
        void update_loss_strike();
        void team_won();
        void team_lost();
        
};  