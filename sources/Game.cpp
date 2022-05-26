#include "Game.hpp"
#include <random>
#include <iostream>
using namespace std;
// Game::Game(Team & home ,Team & away){
//     this->home = &home;
//     this->away = &away;
// }

void Game::points_in_game()const{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> away_team(min_away_points,max_points);
    uniform_int_distribution<> home_team(min_home_points,max_points);
    this->away->points_in_curr_game += away_team(gen);
    this->home->points_in_curr_game += home_team(gen);



    this->home->positive_points += this->home->points_in_curr_game;
    this->home->negative_points += this->away->points_in_curr_game;
    this->away->positive_points += this->away->points_in_curr_game;
    this->away->negative_points += this->home->points_in_curr_game;

    // now clear the points from the curr game
    this->home->points_in_curr_game = 0;
    this->away->points_in_curr_game = 0;

 
}

void Game::winner_losser()const{
    if(this->home->points_in_curr_game > this->away->points_in_curr_game){
        // home team won
        this->home->wins++;
        this->away->losses++;
        

    }else if(this->home->points_in_curr_game < this->away->points_in_curr_game){
        // away team won
        this->away->wins++;
        this->home->losses++;

    }else{
        // draw
    }
}