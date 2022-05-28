#pragma once
#include <vector>
#include "League.hpp"
#include <iostream>
using namespace std;

class Schedule{

    public:
    League *league;
    unsigned int rounds;
    int matches_per_round;
    unsigned int num_teams = 0;
    vector<vector<Game>> matches;
    vector<Game> round_number;
    Schedule(League & league);
    void print_schedule();
    void print_matches_in_round(unsigned int round);
    void run_the_season();
};