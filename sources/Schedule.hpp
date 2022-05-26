#pragma once
#include <vector>
#include "League.hpp"

class Schedule{

    public:
    League *league;
    int rounds;
    int matches_per_round;
    int num_teams = 0;
    vector<vector<Game>> matches;
    Schedule(League & league){
        this->matches_per_round = league.teams->size() / 2;
        this->num_teams = league.teams->size();
        this->rounds = (this->num_teams - 1) * 2;
        for(unsigned int round = 0; round < this->rounds; round++){
            for(unsigned int match = 0; match < this->matches_per_round; match++){
                unsigned int home = (round + match) % ((unsigned int)this->num_teams - 1);
                unsigned int away = ((unsigned int)this->num_teams - 1 - match + round) % ((unsigned int)this->num_teams - 1);
                if(match == 0){
                    away = (unsigned int)this->num_teams - 1;
                }
                this->matches[round][match] = Game(*this->league->teams->at(home) , *this->league->teams->at(away));
            }
        }

    }
    // void print_schedule(){
    //     for(unsigned int round = 0; round < this->rounds; round++){
    //         for(unsigned int match = 0; match < this->matches_per_round; match++){
                
    //         }
    //     }
    // }
    // [[1,2],[3,4],[5,6],[7,8],[9,10],[11,12],[13,14],[15,16],[17,18],[19,20]]
};