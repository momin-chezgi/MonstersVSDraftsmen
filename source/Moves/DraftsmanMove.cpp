#include "innerFunctions.hpp"

intpair drmove(vec2d(char)& grid, draftsman& dr, vector<int> deservedid, const int round){       //returns the new coordinate
    grid[dr.x][dr.y] = 'd';
    print_the_status(grid);
    intpair dr2pos = get_the_move_of_dr(grid, dr, deservedid, round);
    if(dr2pos != make_pair(dr.x,dr.y)){
        if(dr2pos == make_pair(0,0) || dr2pos == make_pair(0,-1)){     //quit the game, either save or not
            return dr2pos;
        }
        if(dr2pos.first%2 != dr2pos.second%2){
            grid[dr2pos.first][dr2pos.second] = '2';
            grid[dr.x][dr.y] = 'D';
        }
        else{
            grid[dr.x][dr.y] = ' ';
            dr.x = dr2pos.first, dr.y = dr2pos.second;
            char a = grid[dr2pos.first][dr2pos.second];
            grid[dr2pos.first][dr2pos.second] = 'D';
            if(a == 'C'){
                return {-dr2pos.first, -dr2pos.second};
            }
        }
    }
    else{
        grid[dr.x][dr.y] = 'Z';
    }
    return {dr2pos.first, dr2pos.second};
}
