#include "innerFunctions.hpp"

void put_the_chance_cubes(vec2d(char) & shown_grid){
    srand(time(0));
    for(int i=0; i<k;){
        int x = rand()%n;
        int y = rand()%m;
        x = 2*x + 1, y = 2*y + 1;
        if(shown_grid[x][y] == ' '){
            shown_grid[x][y] = 'C';
            i++;
        }
    }
}

