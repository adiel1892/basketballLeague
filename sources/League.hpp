#pragma once
#include "Team.hpp"
#include "Game.hpp"
#include <vector>
constexpr int num_of_teams = 20;
using namespace std;
class Team;
class League{
    public:
        League(){
            if(this->nba_teams_names.size() != num_of_teams){
                throw invalid_argument("There must be 20 teams in the league");
            }
            this->teams = new vector<Team*>[num_of_teams];
            for(unsigned int i = 0; i < num_of_teams; i++){
                Team *curr_team = new Team(this->nba_teams_names.at(i));
                curr_team->give_talent();
                this->teams->push_back(curr_team);
            }
        }
        vector<string> nba_teams_names = {
        "Boston Celtics" , "New York Knicks" ,
        "Toronto Raptors" , "Chicago Bulls" ,
        "Cleveland Cavaliers" , "Detroit Pistons" ,
        "Milwaukee Bucks" , "Miami Heat" , 
        "Washington Wizards" ,"Orlando Magic" ,
        "Denver Nuggets" , "New Orleans Pelicans" , 
        "Utah Jazz" , "Golden State Warriors" , 
        "LA Clippers" , "Los Angeles Lakers" , 
        "Phoenix Suns" , "Houston Rockets" , 
        "Memphis Grizzlies" , "San Antonio Spurs"};
        vector<Team*>* teams;
        vector<string> headers_of_league(int places);
        int longest_wins_strike()const;
        int longest_losses_strike()const;
        int positive_points_teams()const;
        string most_positive_points_team()const;
        string lowest_positive_points_team()const;
        string most_negative_points_team()const;
        string lowest_negative_points_team()const;
        void print_teams_with_talent()const;
        void show_table_when_season_over()const;
        void print_top_teams(unsigned int top)const;
};