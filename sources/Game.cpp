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
    // home team gets a random number of points between (55,100)
    int home_points = home_team(gen);
    // away team gets a random number of points between (50,100)
    int away_points = away_team(gen);
    // adding to both teams their talent points with the formula - round(talent * 10)
    int home_talent_extra = round(this->home->talent * 10);
    int away_talent_extra = round(this->away->talent * 10);
    this->away->points_in_curr_game += away_points + away_talent_extra;
    this->home->points_in_curr_game += home_points + home_talent_extra;




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