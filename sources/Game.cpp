#include "Game.hpp"
#include <random>
#include <iostream>
using namespace std;

void Game::points_in_game()const{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> away_team(min_away_points,max_points);
    uniform_int_distribution<> home_team(min_home_points,max_points);
    // home team gets a random number of points between (55,100)
    int home_points = home_team(gen);
    // away team gets a random number of points between (50,100)
    int away_points = away_team(gen);
    // adding to both teams their talent points with the formula - round(talent * 10)
    double home_talent_extra = round(this->home->talent * mul_talent);
    double away_talent_extra = round(this->away->talent * mul_talent);
    this->away->points_in_curr_game += away_points + (int)away_talent_extra;
    this->home->points_in_curr_game += home_points + (int)home_talent_extra;
    this->home->positive_points += this->home->points_in_curr_game;
    this->home->negative_points += this->away->points_in_curr_game;
    this->away->positive_points += this->away->points_in_curr_game;
    this->away->negative_points += this->home->points_in_curr_game;
}

void Game::winner_loser()const{
    if(this->home->points_in_curr_game > this->away->points_in_curr_game){
        // home team won
        this->update_winner_loser(*home , *away);
    }else if(this->home->points_in_curr_game < this->away->points_in_curr_game){
        // away team won
        this->update_winner_loser(*away , *home);
    }else{
        // draw
        if(this->home->curr_win_strike > this->away->curr_win_strike){
            this->update_winner_loser(*home , *away);
        }else if(this->home->curr_win_strike < this->away->curr_win_strike){
            this->update_winner_loser(*away , *home);
        }else{
            // draw , and both with same wins strike - give the advantage to the away team.
            this->update_winner_loser(*away , *home);
        }
    }
    // now clear the points from the curr game
    this->home->points_in_curr_game = 0;
    this->away->points_in_curr_game = 0;
}

void Game::print_game()const{
    cout << this->home->name << " VS. " << this->away->name << endl;
}

void Game::start_game()const{
    this->points_in_game();
    this->winner_loser();
}

// The first team won , the second team lost.
void Game::update_winner_loser(Team & winner , Team & loser)const{
    winner.team_won();
    loser.team_lost();
}