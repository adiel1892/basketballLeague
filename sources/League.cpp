#include "League.hpp"
#include <iostream>
using namespace std;


void League::print_teams_with_talent(){
    for(unsigned int i = 0; i < this->teams->size(); i++){
        cout << i + 1 << ") " << this->teams->at(i)->name << " - " << this->teams->at(i)->talent << endl;
    }
}