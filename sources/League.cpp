#include "League.hpp"
#include <iostream>
#include <algorithm>
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

string League::most_positive_points_team(){
    int points = this->teams->at(0)->positive_points;
    unsigned int res = 0;
    for(unsigned int i = 0; i < this->teams->size(); i++){
        if(this->teams->at(i)->positive_points > points){
            points = this->teams->at(i)->positive_points;
            res = i;
        }
    }
    return this->teams->at(res)->name;
}

string League::lowest_positive_points_team(){
    int points = this->teams->at(0)->positive_points;
    unsigned int res = 0;
    for(unsigned int i = 0; i < this->teams->size(); i++){
        if(this->teams->at(i)->positive_points < points){
            points = this->teams->at(i)->positive_points;
            res = i;
        }
    }
    return this->teams->at(res)->name;
}

string League::most_negative_points_team(){
    int points = this->teams->at(0)->negative_points;
    unsigned int res = 0;
    for(unsigned int i = 0; i < this->teams->size(); i++){
        if(this->teams->at(i)->negative_points > points){
            points = this->teams->at(i)->negative_points;
            res = i;
        }
    }
    return this->teams->at(res)->name;
}

string League::lowest_negative_points_team(){
    int points = this->teams->at(0)->negative_points;
    unsigned int res = 0;
    for(unsigned int i = 0; i < this->teams->size(); i++){
        if(this->teams->at(i)->negative_points < points){
            points = this->teams->at(i)->negative_points;
            res = i;
        }
    }
    return this->teams->at(res)->name;
}

bool compare_teams(Team *a , Team *b){
    if(a->wins > b->wins){
        return true;
    }else if(a->wins < b->wins){
        return false;
    }else if(a->positive_points - a->negative_points > b->positive_points - b->negative_points){
        return true;
    }else{
        return false;
    }
}

void League::show_table_when_season_over(){
    sort(this->teams->begin() , this->teams->end() ,compare_teams);
    for(unsigned int i = 0; i < this->teams->size(); i++){
        cout << i + 1 << ") " << this->teams->at(i)->name <<  " , wins: " << this->teams->at(i)->wins << " , difference: " << this->teams->at(i)->positive_points - this->teams->at(i)->negative_points << endl;
    }
}
