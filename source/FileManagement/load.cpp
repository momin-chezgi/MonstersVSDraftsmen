#include "innerFunctions.hpp"

status load_the_game(int index){
    is_saved_game = true;
    status savedg;

    FILE* fptr = fopen("../data/data.txt", "r"); 
    char linebuf[LINEMAX];

    skip_games(fptr, index);

    
    // 1. The number of round
    read_int(fptr, &savedg.round);

    // 2. The last player that it was his turn
    read_int(fptr, &savedg.lastplayer);

    // 3. The numbers of the draftsmen and their infos: 
    // <id,x,y,temp_token,token_limit,winned,defeated>
    read_draftsmen(fptr, savedg.drs);

    // 4. The numbers of the monsters and their coordinates: <x,y>
    read_intpairs(fptr, savedg.mns);

    // 5. The coordinate of the light source: <x,y>
    read_intpairs(fptr, savedg.lighpos);

    // 6. The numbers of walls and their coordinates: <x,y>
    read_intpairs(fptr, savedg.walls);

    // 7. The numerbs of 2-round walls and their coordinates: <x,y>
    read_intpairs(fptr, savedg.temp2);

    // 8. The numbers of 1-round walls and their coordinates: <x,y>
    read_intpairs(fptr, savedg.temp1);

    // 9. The numbers of the chance cubes and their coordinates: <x,y>
    read_intpairs(fptr, savedg.chancecubes);

    // 10,11. dimensions of the grid
    read_int(fptr, &savedg.n);
    read_int(fptr, &savedg.m);
    

    fclose(fptr);

    return savedg;
}