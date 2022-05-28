#include <iostream>
#include <random>
#include "Game.hpp"
#include "Team.hpp"
#include "League.hpp"
#include "Schedule.hpp"
#include <iostream>
using namespace std;



int main(){
    cout << "working until now" << endl;
    League league{};
    // league.print_teams_with_talent();
    // cout << league.longest_losses_strike() << endl;
    Schedule sch(league);
    sch.run_the_season();
    league.show_table_when_season_over();
    league.print_top_teams(5);
    league.longest_wins_strike();
    league.longest_losses_strike();
    league.most_positive_points_team();
    league.lowest_positive_points_team();
    league.most_negative_points_team();
    league.lowest_negative_points_team();
    
    

    



}