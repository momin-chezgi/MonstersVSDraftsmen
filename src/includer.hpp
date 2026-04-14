#ifndef INCLUDER_HPP
#define INCLUDER_HPP

#include <iostream>
#include <cmath>
#include <algorithm>
#include <random>
#include <vector>
#include <fstream>
#include <cstring>


#define cell Node
#define vec2d(type) vector<vector<type>>
#define intpair pair<int,int>
#ifdef _WIN32 
#include <windows.h>
#endif
using namespace std;

const int LINEMAX = 37000;

extern int n, m, k;
extern int drnum, mnnum, wlnum;
extern bool is_saved_game;

extern intpair light_source_pos;
extern vector<intpair> mnpos;

#endif // INCLUDER_HPP