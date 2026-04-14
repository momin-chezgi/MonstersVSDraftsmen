#pragma once

#include "../classes.hpp"


bool read_int(FILE* fptr, int* out);
bool read_intpairs(FILE* fptr, vector<intpair>& out);
bool read_draftsmen(FILE* fptr, vector<draftsman>& out);
bool skip_games(FILE* fptr, int index);
FILE* open_data_file(const char* filename, const char* mode);
int number_of_games();
int update_number_of_games();
