#ifndef MAZEGEN_HPP
#define MAZEGEN_HPP


#include "includer.hpp"
#include "interpreter.hpp"

/*
 limits of  this variables:
    drnum+mnnum : [1 , (n*m)/9]
        why? because each draftman/monster
                  threatens up to 8 cells around it that 
                  can't contain monsters/draftsmen.
    wlnum : [0 , n*m - n - m]
*/

int mazegenerator(vec2d(char)& shown_grid, int n_input  = n, int m_input = m,
                  int drnum_input = drnum, int mnnum_input = mnnum,
                  int wlnum_input = wlnum); // generates the maze and places the light source, monsters, draftsmen, chance cubes and walls. It also updates the global variables n,m,drnum,mnnum,wlnum if the input parameters are not -1.

// main chain of functions:
//1.
intpair place_the_lightsource(vec2d(char)& shown_grid);
//2.
void put_the_walls(intpair light_source_pos,vec2d(cell) &grid, vec2d(char)& shown_grid, vec2d(int) &connected);
//3.
void place_the_draftsmen(vec2d(char) & shown_grid);
//4.
void place_the_monsters(vec2d(char) & shown_grid);
//5.
void put_the_chance_cubes(vec2d(char) & shown_grid);

// sub-algorithms:
void create_the_spanning_tree(vec2d(cell) & grid, intpair light_source_pos,vec2d(int) & connected, vec2d(char) & shown_grid);
int fix_the_wrong_walls(int i1, int j1, int direction);
intpair where_is_the_neighbor(int i, int j, int direction);
pair<intpair, intpair> shown2real_coord(int a, int b, char cell_type);
bool are_there_no_enemy_nearby(vec2d(char) & shown_grid, int i, int j, char cell_type);
inline void remove_dots(vec2d(char)& shown_grid);




#endif //MAZEGEN_HPP