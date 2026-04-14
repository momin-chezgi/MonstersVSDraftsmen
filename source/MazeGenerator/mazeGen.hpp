#ifndef MAZEGEN_HPP
#define MAZEGEN_HPP


#include "../includer.hpp"
#include "../Interface/Interface.hpp"

/*
 limits of  this variables:
    drnum+mnnum : [1 , (n*m)/9]
        why? because each draftman/monster
                  threatens up to 8 cells around it that 
                  can't contain monsters/draftsmen.
    wlnum : [0 , n*m - n - m]
*/

int mazegenerator(vec2d(char)& shown_grid, 
                  int n_input  = n, int m_input = m,
                  int drnum_input = drnum, int mnnum_input = mnnum,
                  int wlnum_input = wlnum
                  ); 

//  generates the maze and places the light source, monsters, draftsmen, chance cubes and walls.
//  It also updates the global variables n,m,drnum,mnnum,wlnum if the input parameters are not -1.

//  the maze is generated in shown_grid, which should be a 2D char vector of size (2*n+1) x (2*m+1) 
// with all cells initialized to ' ' before calling this function.
// The function returns 0 after generating the maze.


#endif //MAZEGEN_HPP