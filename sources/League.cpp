#include "League.hpp"
#include <iostream>
using namespace std;


void League::print_teams_with_talent(){
    for(unsigned int i = 0; i < this->teams->size(); i++){
        cout << i + 1 << ") " << this->teams->at(i)->name << " - " << this->teams->at(i)->talent << endl;
    }
}

int League::longest_wins_strike(){
    int res = 0;
    for(unsigned int i = 0; i < this->teams->size(); i++){
        if(this->teams->at(i)->longest_wins_strike > res){
            res = this->teams->at(i)->longest_wins_strike;
        }
    }
    return res;
}

int League::longest_losses_strike(){
    int res = 0;
    for(unsigned int i = 0; i < this->teams->size(); i++){
        if(this->teams->at(i)->longest_losses_strike > res){
            res = this->teams->at(i)->longest_losses_strike;
        }
    }
    return res;
}

int League::positive_points_teams(){
    int res = 0;
    for(unsigned int i = 0; i < this->teams->size(); i++){
        if(this->teams->at(i)->positive_points - this->teams->at(i)->negative_points > 0){
            res++;
        }
    }
    return res;
}