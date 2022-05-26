#include "Team.hpp"
#include <random>
using namespace std;

void Team::give_talent(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> talent_for_team(0,1.0);
    this->talent = talent_for_team(gen);

}