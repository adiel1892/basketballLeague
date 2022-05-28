#include <iostream>
#include <random>
#include "sources/Game.hpp"
#include "sources/Team.hpp"
#include "sources/League.hpp"
#include "sources/Schedule.hpp"
using namespace std;


TEST_CASE(){
    cout << "Starting the test!" << endl;
    League league{};
    CHECK(league.teams->size() == 20);
    CHECK(league.longest_losses_strike == 0);
    CHECK(league.longest_wins_strike == 0);
    Schedule sch(league);
    CHECK(sch.rounds == 38);
    CHECK(sch.num_teams == 20);
    CHECK(sch.matches_per_round == 10);    
    sch.run_the_season();


}
