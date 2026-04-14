#include "innerFunctions.hpp"

void put_the_walls(intpair light_source_pos, 
    vec2d(cell) &grid, vec2d(char) &shown_grid,
    vec2d(int) &connected){

    int walls_placed = 0;

    // first, create the spanning tree to ensure connectivity
    create_the_spanning_tree(grid, light_source_pos, connected, shown_grid);
    
    vector<intpair> possible_walls; // Note: the coordinate is not the real one, it's the coordinate in shown_grid

    //then we can place additional walls randomly on the remaining possible wall positions
    // collect all possible wall positions
    //vertical walls
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m-1; j++){
            if(shown_grid[2*i +1][2*j +2] == ' '){
                possible_walls.push_back({2*i +1, 2*j +2});
            }
        }
    }
    //horizontal walls
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m; j++){
            if(shown_grid[2*i +2][2*j +1] == ' '){
                possible_walls.push_back({2*i +2, 2*j +1});
            }
        }
    }
    // shuffle the possible walls
    random_device rd;          
    mt19937 g(rd());            
    shuffle(possible_walls.begin(), possible_walls.end(), g);
    // place walls until we reach wlnum
    for(int i = 0; i < possible_walls.size() && walls_placed < wlnum; i++){
        intpair wall_pos = possible_walls[i];
        shown_grid[wall_pos.first][wall_pos.second] = '#';
        walls_placed++;
    }

    // finally, replace all remaining '.' with ' ' to finalize the maze
    for (int i = 1; i < 2*n; i+=2){
        for (int j = 2; j< 2*m; j+=2){
            if(shown_grid[i][j] == '.'){
                shown_grid[i][j] = ' ';
            }
        }
    }
}
