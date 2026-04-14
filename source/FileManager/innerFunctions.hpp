#pragma once

#include "../classes.hpp"


static bool read_int(FILE* fptr, int* out);
static bool read_intpairs(FILE* fptr, vector<intpair>& out);
static bool read_draftsmen(FILE* fptr, vector<draftsman>& out);
inline void skip_games(FILE* fptr, int index);
int number_of_games();
int update_number_of_games();

