#pragma once
#include "Team.hpp"
#include "Game.hpp"
#include <vector>

class League{

    public:
        vector<Team*>* teams;
        vector<string> headers_of_league(int places);
        int longest_wins_strike();
        int longest_losses_strike();
        int positive_points_teams();
        vector<string> relegation_teams();
        string most_points_team();
        string lowest_points_team();
};