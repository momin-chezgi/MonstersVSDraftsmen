#pragma once

#include "../classes.hpp"

status importer(bool wellcom = true, int given_n = -1, int given_m = -1,
                  int given_drnum = -1, int given_mnnum = -1);

intpair get_the_move_of_dr(vec2d(char)& grid, draftsman& dr , vector<int>& announcedid, const int round=0); //returns the coordinate of moved draftsman

void magic_transfer(vector<intpair>& mnpos, vec2d(char)& grid);

void print_the_status(vec2d(char)& shown_grid);

void print_the_ranking(vector<int>& winners, vector<int>& losers);

