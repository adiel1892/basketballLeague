#include <iostream>
#include <random>
// #include "Game.cpp"
// #include "Team.cpp"
// #include "League.cpp"
// #include "Schedule.cpp"
constexpr int min_away_points = 50;
constexpr int min_home_points = 55;
constexpr int max_points = 100;
using namespace std;


int main(){
    cout << "working until now" << endl;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> away_team(min_away_points,max_points);
    std::uniform_real_distribution<> talent(0,1.0);
    // cout << away_team(gen) << endl;
    // srand((unsigned) time(0));
    double r = talent(gen);
    cout << r << endl;
    cout << round(r * 10) << endl;



    // srand((unsigned) time(0));
    // for (int i = 0; i < 20; ++i) {
    //         cout << (float)rand() / (float)RAND_MAX << endl;
    // }
}