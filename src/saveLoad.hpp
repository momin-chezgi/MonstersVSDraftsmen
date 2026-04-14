#ifndef SAVEANDLOAD_HPP
#define SAVEANDLOAD_HPP

#include "classes.hpp"

int number_of_games();
int save_the_game(status& game);
status load_the_game(int index);

#endif //SAVEANDLOAD_HPP