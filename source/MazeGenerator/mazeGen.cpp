#include "innerFunctions.hpp"

int mazegenerator(vec2d(char)& shown_grid, int n_input, int m_input,
                  int drnum_input, int mnnum_input,
                  int wlnum_input){
        // if you want to give just some parameters fill others with -1;

    n = n_input;
    m = m_input;
    drnum = drnum_input;
    mnnum = mnnum_input;
    wlnum = wlnum_input;

    vec2d(cell) grid(n, vector<cell>(m));
    vec2d(int) connected(n, vector<int>(m, 0));

    // initialize cells, corners and the space between cells that will be placed by walls later
    for (int i = 0; i < n; i++){
        for(int j=0; j< m; j++){
            shown_grid[2*i+1][2*j+1] = ' ';     
            shown_grid[2 * i][2 * j] = '#';
            shown_grid[2 * i][2 * j + 1] = ' ';
            shown_grid[2 * i + 1][2 * j] = ' ';
        }
    }
    for(int i=0; i<=2*n; i++){
        shown_grid[i][0] = shown_grid[i][2*m] = '#';
    }
    for(int j=0; j<=2*m; j++){
        shown_grid[0][j] = shown_grid[2*n][j] = '#';
    }
    
    //initialize the cells of grid[][]
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            grid[i][j].x = grid[i][j].xp = i;
            grid[i][j].y = grid[i][j].yp = j;
        }
    }

    //1. place the light source
    intpair light_source_pos = place_the_lightsource(shown_grid);
    connected[light_source_pos.first][light_source_pos.second] = 1;
    
    //2. place the walls
    put_the_walls(light_source_pos, grid, shown_grid, connected);
    
    //3. place the draftsmen
    place_the_draftsmen(shown_grid);
    
    //4. place the monsters
    place_the_monsters(shown_grid);

    //5. Put the chance cubes
    put_the_chance_cubes(shown_grid);

    remove_dots(shown_grid);

    return 0;
}