
#include "innerFunctions.hpp"


void clear_the_screen()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int coor2id4monster(int x, int y, vector<intpair>& mnpos){
    for(int mn=0; mn<mnpos.size(); mn++){
        if(mnpos[mn] == make_pair(x,y)) return mn;
    }
    return -1;
}