#include "innerFunctions.hpp"

intpair place_the_lightsource(vec2d(char)& shown_grid){
    srand(time(0));
    int i = rand() % n;
    int j = rand() % m;
    shown_grid[2 * i + 1][2 * j + 1] = 'S';
    return {i, j};
}
