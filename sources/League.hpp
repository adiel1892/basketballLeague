#pragma once
#include "Team.hpp"
#include "Game.hpp"
#include <vector>
constexpr int num_of_teams = 20;
using namespace std;

class League{

    public:
        League(vector<string> names_of_teams){
            if(names_of_teams.size() != 20){
                throw invalid_argument("There must be 20 teams in the league!");
            }
            this->teams = new vector<Team*>[num_of_teams];
            for(unsigned int i = 0; i < names_of_teams.size(); i++){
                Team curr_team(names_of_teams.at(i));
                curr_team.give_talent();
                this->teams->push_back(&curr_team);
                
            }
            
        }
        vector<Team*>* teams;

        vector<string> headers_of_league(int places);
        int longest_wins_strike();
        int longest_losses_strike();
        int positive_points_teams();
        std::vector<std::string> relegation_teams();
        std::string most_points_team();
        std::string lowest_points_team();
};