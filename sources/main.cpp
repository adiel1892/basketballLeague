#include <iostream>
#include <random>
#include "Game.hpp"
#include "Team.hpp"
#include "League.hpp"
#include "Schedule.hpp"
using namespace std;



int main(){
    cout << "working until now" << endl;
    vector<string> nba_teams_names = {
        "Boston Celtics" , "New York Knicks" ,
        "Toronto Raptors" , "Chicago Bulls" ,
        "Cleveland Cavaliers" , "Detroit Pistons" ,
        "Milwaukee Bucks" , "Miami Heat" , 
        "Washington Wizards" ,"Orlando Magic" ,
        "Denver Nuggets" , "New Orleans Pelicans" , 
        "Utah Jazz" , "Golden State Warriors" , 
        "LA Clippers" , "Los Angeles Lakers" , 
        "Phoenix Suns" , "Houston Rockets" , 
        "Memphis Grizzlies" , "San Antonio Spurs"
    };
    League nba_league(nba_teams_names);
    for(unsigned int i = 0; i < nba_league.teams->size(); i++){
        cout << nba_league.teams->at(i)->name << nba_league.teams->at(i)->talent << endl;
    }



}