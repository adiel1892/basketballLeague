#include "Team.hpp"
#include <random>
using namespace std;

void Team::give_talent(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> talent_for_team(0,1.0);
    this->talent = talent_for_team(gen);

}

// if the team lost - take the curr wins and update the longest win strike, because the win strike is over.
// if the team won - take the curr losses and update the longest loss strike, because the loss strike is over.
void Team::update_win_strike(){
    if(this->curr_win_strike > this->longest_wins_strike){
        this->longest_wins_strike = this->curr_win_strike;
    }
    this->curr_win_strike = 0;
}

void Team::update_loss_strike(){
    if(this->curr_loss_strike > this->longest_losses_strike){
        this->longest_losses_strike = this->curr_loss_strike;
    }
    this->curr_loss_strike = 0;
}

bool Team::operator<(Team & other){
    if(this->wins < other.wins){
        return true;
    }else if(this->wins < other.wins){
        return false;
    }else if(this->positive_points - this->negative_points < other.positive_points - other.negative_points){
        return true;
    }else{
        return false;
    }
}