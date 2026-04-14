#include "innerFunctions.hpp"

intpair mnmove(vec2d(char)& grid,const intpair mnpos, vec2d(int)& has_seen){
    int mnx = mnpos.first;
    int mny = mnpos.second;
    intpair drpos = Im_hungry(grid, mnpos, has_seen);
    for (int l=0; l<2; l++){
        //If it can close horizantelly...
        if(drpos.second < mny && grid[mnx][mny - 1] == ' ' && mny>2 && grid[mnx][mny-2] != 'S' && grid[mnx][mny-2] != 'M'){
            mny -= 2;
            continue;
        }
        if(drpos.second > mny && grid[mnx][mny + 1] == ' ' && mny<(2*m-2) && grid[mnx][mny+2] != 'S' && grid[mnx][mny+2] != 'M'){
            mny += 2;
            continue;
        }
        //else closes vertically...
        if(drpos.first < mnx && grid[mnx - 1][mny] == ' ' && mnx>2 && grid[mnx-2][mny] != 'S' && grid[mnx-2][mny] != 'M'){
            mnx -= 2;
            continue;
        }
        if(drpos.first > mnpos.first && grid[mnx + 1][mny] == ' ' && mnx<(2*n-2) && grid[mnx+2][mny] != 'S' && grid[mnx+2][mny] != 'M'){
            mnx += 2;
            continue;
        }
        if(grid[mnx][mny] == 'D' || grid[mnx][mny] == 'd' || grid[mnx][mny] == 'Z'){
            break;
        }
    }
    // update the monster's position
    grid[mnpos.first][mnpos.second] = ' ';
    grid[mnx][mny] = 'M';

    return {mnx,mny};
}

