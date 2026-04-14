#include "innerFunctions.hpp"

int save_the_game(status& game){    //returns the index of the last-appended game
    /*
    The format of 'data' file:
    before the statuses, the number of status is written
    every status's first information is the number of it that begins
    every line contains (in order) this infos:
    */

    int gamenum = update_number_of_games();

    FILE* fptr = fopen("../data/data.txt", "a");
    if(fptr==NULL)return -1;

    // 1. The number of round
    fprintf(fptr, "%d\n", game.round-1);
    
    // 2. The last player that it was his turn
    fprintf(fptr, "%d\n", game.lastplayer);

    // 3. The numbers of the draftsmen and their infos: 
    // <id,x,y,temp_token,token_limit,winned,defeated>
    fprintf(fptr, "%ld ", game.drs.size());
    for(int i=0; i<dr.size(); i++){
        fprintf(fptr, "<%d,%d,%d,%d,%d,%d,%d> ",
            game.drs[i].id, game.drs[i].x, game.drs[i].y, game.drs[i].temp_token,
            game.drs[i].token_limit, game.drs[i].winned, game.drs[i].defeated);
    }
    fprintf(fptr, "\n");

    // 4. The numbers of the monsters and their coordinates: <x,y>
    fprintf(fptr, "%d ", mnnum);
    for(int i=0; i<mnpos.size(); i++){
        fprintf(fptr, "<%d,%d> ",game.mns[i].first,game.mns[i].second);
    }
    fprintf(fptr, "\n");

    // 5. The coordinate of the light source: <x,y>
    fprintf(fptr, "1 <%d,%d>\n", game.lighpos[0].first, game.lighpos[0].second);

    // 6. The numbers of walls and their coordinates: <x,y>
    fprintf(fptr, "%d ", wlnum);
    for(int i=0; i<game.walls.size(); i++) fprintf(fptr, "<%d,%d> ",game.walls[i].first, game.walls[i].second);
    fprintf(fptr, "\n");

    // 7. The numerbs of 2-round walls and their coordinates: <x,y>
    fprintf(fptr, "%ld ", game.temp2.size());
    for(int i=0; i<game.temp2.size(); i++) fprintf(fptr, "<%d,%d> ",game.temp2[i].first, game.temp2[i].second);
    fprintf(fptr, "\n");

    // 8. The numbers of 1-round walls and their coordinates: <x,y>
    fprintf(fptr, "%ld ", game.temp1.size());
    for(int i=0; i<game.temp1.size(); i++) fprintf(fptr, "<%d,%d> ",game.temp1[i].first, game.temp1[i].second);
    fprintf(fptr, "\n");

    // 9. The numbers of the chance cubes and their coordinates: <x,y>
    fprintf(fptr, "%ld ", game.chancecubes.size());
    for(int i=0; i<game.chancecubes.size(); i++) fprintf(fptr, "<%d,%d> ", game.chancecubes[i].first, game.chancecubes[i].second);
    fprintf(fptr, "\n");

    // 10,11. dimensions of the grid
    fprintf(fptr, "%d\n", game.n);
    fprintf(fptr, "%d\n", game.m);

    fclose(fptr);

    return gamenum;
}