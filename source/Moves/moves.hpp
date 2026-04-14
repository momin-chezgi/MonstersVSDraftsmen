#ifndef MOVES_HPP
#define MOVES_HPP

#include "../includer.hpp"
#include "../Interface/Interface.hpp"

intpair drmove(vec2d(char)& grid, draftsman& dr, vector<int> deservedid, const int round);       //returns the new coordinate
intpair mnmove(vec2d(char)& grid,const intpair mnpos, vec2d(int)& has_seen);            //returns the new coordinate
void earthquake(vec2d(char)& grid, vector<draftsman>& draftsman,vector<intpair>& mnpos, int remain_dr);

#endif //MOVES_HPP