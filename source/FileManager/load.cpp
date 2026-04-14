#include "innerFunctions.hpp"

status load_the_game(int index){
    is_saved_game = true;
    status savedg;

    FILE* fptr = open_data_file("data.txt", "r"); 
    if(fptr == NULL){
        cerr << "Error: data.txt not found.\n";
        is_saved_game = false;
        return savedg;
    }

    if(!skip_games(fptr, index)){
        cerr << "Error: Save slot #" << index << " is invalid.\n";
        fclose(fptr);
        is_saved_game = false;
        return savedg;
    }

    
    // 1. The number of round
    if(!read_int(fptr, &savedg.round)){
        cerr << "Error: Failed to read saved round.\n";
        fclose(fptr);
        is_saved_game = false;
        return status{};
    }

    // 2. The last player that it was his turn
    if(!read_int(fptr, &savedg.lastplayer)){
        cerr << "Error: Failed to read saved turn.\n";
        fclose(fptr);
        is_saved_game = false;
        return status{};
    }

    // 3. The numbers of the draftsmen and their infos: 
    // <id,x,y,temp_token,token_limit,winned,defeated>
    if(!read_draftsmen(fptr, savedg.drs)){
        cerr << "Error: Failed to read draftsmen data.\n";
        fclose(fptr);
        is_saved_game = false;
        return status{};
    }

    // 4. The numbers of the monsters and their coordinates: <x,y>
    if(!read_intpairs(fptr, savedg.mns)){
        cerr << "Error: Failed to read monsters data.\n";
        fclose(fptr);
        is_saved_game = false;
        return status{};
    }

    // 5. The coordinate of the light source: <x,y>
    if(!read_intpairs(fptr, savedg.lighpos)){
        cerr << "Error: Failed to read light source data.\n";
        fclose(fptr);
        is_saved_game = false;
        return status{};
    }

    // 6. The numbers of walls and their coordinates: <x,y>
    if(!read_intpairs(fptr, savedg.walls)){
        cerr << "Error: Failed to read walls data.\n";
        fclose(fptr);
        is_saved_game = false;
        return status{};
    }

    // 7. The numerbs of 2-round walls and their coordinates: <x,y>
    if(!read_intpairs(fptr, savedg.temp2)){
        cerr << "Error: Failed to read temp2 wall data.\n";
        fclose(fptr);
        is_saved_game = false;
        return status{};
    }

    // 8. The numbers of 1-round walls and their coordinates: <x,y>
    if(!read_intpairs(fptr, savedg.temp1)){
        cerr << "Error: Failed to read temp1 wall data.\n";
        fclose(fptr);
        is_saved_game = false;
        return status{};
    }

    // 9. The numbers of the chance cubes and their coordinates: <x,y>
    if(!read_intpairs(fptr, savedg.chancecubes)){
        cerr << "Error: Failed to read chance cubes data.\n";
        fclose(fptr);
        is_saved_game = false;
        return status{};
    }

    // 10,11. dimensions of the grid
    if(!read_int(fptr, &savedg.n) || !read_int(fptr, &savedg.m)){
        cerr << "Error: Failed to read grid size.\n";
        fclose(fptr);
        is_saved_game = false;
        return status{};
    }
    

    fclose(fptr);

    return savedg;
}
