#include "Schedule.hpp"
#include <iostream>
using namespace std;


Schedule::Schedule(League & league){
    this->league = &league;
    this->matches_per_round = league.teams->size() / 2;
    this->num_teams = league.teams->size();
    this->rounds = (this->num_teams - 1) * 2;
    for(unsigned int round = 0; round < this->rounds; round++){
        for(unsigned int match = 0; match < this->matches_per_round; match++){
            if(round + 1 <= 19){
                unsigned int home = (round + match) % ((unsigned int)this->num_teams - 1);
                unsigned int away = ((unsigned int)this->num_teams - 1 - match + round) % ((unsigned int)this->num_teams - 1);
                if(match == 0){
                    away = (unsigned int)this->num_teams - 1;
                }
                Game *tmp = new Game(*this->league->teams->at(home) , *this->league->teams->at(away));
                this->round_number.push_back(*tmp);
                if(this->round_number.size() == this->matches_per_round){
                    this->matches.push_back(this->round_number);
                    this->round_number.clear();
                }
            }else{
                unsigned int away = (round + match) % ((unsigned int)this->num_teams - 1);
                unsigned int home = ((unsigned int)this->num_teams - 1 - match + round) % ((unsigned int)this->num_teams - 1);
                if(match == 0){
                    home = (unsigned int)this->num_teams - 1;
                }
                Game *tmp = new Game(*this->league->teams->at(home) , *this->league->teams->at(away));
                this->round_number.push_back(*tmp);
                if(this->round_number.size() == this->matches_per_round){
                    this->matches.push_back(this->round_number);
                    this->round_number.clear();
                }
            }
        }
    }
}

void Schedule::print_schedule(){
        for(unsigned int round = 0; round < this->rounds; round++){
            cout << "round number " << round + 1 << ":" << endl;
            for(unsigned int match = 0; match < this->matches_per_round; match++){
                cout << this->matches[round][match].home->name << " VS. " << this->matches[round][match].away->name << endl; 
            }
        }
}

void Schedule::print_matches_in_round(unsigned int round){
    cout << "round number " << round << ":" << endl;
    for(unsigned int match = 0; match < this->matches_per_round; match++){
        cout << this->matches[round - 1][match].home->name << " VS. " << this->matches[round - 1][match].away->name << endl; 
    }
}

void Schedule::run_the_season(){
    for(unsigned int round = 0; round < this->rounds; round++){
        for(unsigned int match = 0; match < this->matches_per_round; match++){
           this->matches[round][match].start_game();
        }
    }
}