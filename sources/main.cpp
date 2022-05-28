#include <iostream>
#include <random>
#include "Game.hpp"
#include "Team.hpp"
#include "League.hpp"
#include "Schedule.hpp"
constexpr int top = 5;
using namespace std;

int main(){
    League league{};
    Schedule sch(league);
    sch.run_the_season();
    league.show_table_when_season_over();
    league.print_top_teams(top);
    league.longest_wins_strike();
    league.longest_losses_strike();
    league.most_positive_points_team();
    league.lowest_positive_points_team();
    league.most_negative_points_team();
    league.lowest_negative_points_team();
    
    

    



}