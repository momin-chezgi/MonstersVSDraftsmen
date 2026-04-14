#include "innerFunctions.hpp"

void place_the_draftsmen(vec2d(char) & shown_grid){
    int darftsmen_placed = 0;
    while(darftsmen_placed < drnum){
        srand(time(0));
        int i = rand() % n;
        int j = rand() % m;
        if(shown_grid[2*i +1][2*j +1] == ' '){
            shown_grid[2*i +1][2*j +1] = 'D';
            darftsmen_placed++;
        }
    }
}