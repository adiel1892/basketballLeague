#pragma once
#include "Team.hpp"
#include "Game.hpp"
#include <vector>
using namespace std;

class League{

    public:
        vector<Team*>* teams;

        vector<string> headers_of_league(int places);
        int longest_wins_strike();
        int longest_losses_strike();
        int positive_points_teams();
        std::vector<std::string> relegation_teams();
        std::string most_points_team();
        std::string lowest_points_team();
};