#include <iostream>
#include <random>
// #include "Game.cpp"
// #include "Team.cpp"
// #include "League.cpp"
// #include "Schedule.cpp"
using namespace std;

int main(){
    cout << "working until now" << endl;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> away_team(50,100);
    cout << away_team(gen) << endl;
}