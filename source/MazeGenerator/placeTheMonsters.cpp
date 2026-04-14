#include "innerFunctions.hpp"

void place_the_monsters(vec2d(char) & shown_grid){
    if(mnnum < drnum){
        int monsters_placed = 0;
        while(monsters_placed < mnnum){
            srand(time(0));
            int i = rand() % n;
            int j = rand() % m;
            if(shown_grid[2*i +1][2*j +1] == ' '  && are_there_no_enemy_nearby(shown_grid, i, j, 'M')){
                shown_grid[2*i +1][2*j +1] = 'M';
                monsters_placed++;
            }
        }    
    }
    if(mnnum >= drnum){
        int monsters_placed = 0;
        while(monsters_placed < mnnum){
            srand(time(0));
            int i = rand() % n;
            int j = rand() % m;
            if(shown_grid[2*i +1][2*j +1] == ' '  && are_there_no_enemy_nearby(shown_grid, i, j, 'D')){
                shown_grid[2*i +1][2*j +1] = 'M';
                monsters_placed++;
            }    
        }
    }
}
