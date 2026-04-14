
#include "innerFunctions.hpp"


static void clear_the_screen()
{
    for(int i=0; i<80; i++) cout << endl;
}

static int coor2id4monster(int x, int y, vector<intpair>& mnpos){
    for(int mn=0; mn<mnpos.size(); mn++){
        if(mnpos[mn] == make_pair(x,y)) return mn;
    }
    return -1;
}