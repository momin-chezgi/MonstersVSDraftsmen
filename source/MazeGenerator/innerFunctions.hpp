#pragma once

#include "../includer.hpp"
#include "../Interface/Interface.hpp"

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
//pair<intpair, intpair> shown2real_coord(int a, int b, char cell_type);
bool are_there_no_enemy_nearby(vec2d(char) & shown_grid, int i, int j, char cell_type);
void remove_dots(vec2d(char)& shown_grid);



