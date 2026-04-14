
#include "innerFunctions.hpp"

static bool read_int(FILE* fptr, int* out){
    char linebuf[LINEMAX];
    if(!fgets(linebuf, LINEMAX, fptr)) return false;
    return sscanf(linebuf, "%d", out) == 1;
}

static bool read_intpairs(FILE* fptr, vector<intpair>& out){
    char linebuf[LINEMAX];
    if(!fgets(linebuf, LINEMAX, fptr)) return false;

    char* p = linebuf;
    int count = 0;
    sscanf(p, "%d", &count);
    p = strchr(p, '<');
    for(int i=0; i<count; i++){
        int x, y;
        if(sscanf(p, " <%d,%d>", &x, &y) != 2) return false;
        out.push_back({x,y});
        p = strchr(p, '>') + 1;
    }
    return true;
}

static bool read_draftsmen(FILE* fptr, vector<draftsman>& out){
    char linebuf[LINEMAX];
    if(!fgets(linebuf, LINEMAX, fptr)) return false;

    char* p = linebuf;
    int count = 0;
    sscanf(p, "%d", &count);
    p = strchr(p, '<')-1;
    for(int i=0; i<count; i++){
        int id, x, y, temp_token, token_limit, winned, defeated;
        if(sscanf(p, " <%d,%d,%d,%d,%d,%d,%d>",
                    &id, &x, &y, &temp_token, &token_limit, &winned, &defeated ) != 7) return false;
        out.emplace_back(draftsman{id,x,y,temp_token,token_limit,(bool)winned,(bool)defeated});
        p = strchr(p, '>') + 1;
    }
    return true;
}

inline void skip_games(FILE* fptr, int index){
    char linebuf[LINEMAX];
    for(int i=0; i<11*index+1; i++){
        fgets(linebuf, LINEMAX, fptr);
    }
}

int update_number_of_games() {
    FILE* datap = fopen("../data/data.txt", "r");
    FILE* tempp = fopen("../data/temp.txt", "w");
    if(datap == NULL || tempp == NULL){
        cerr << "Error: Files don't open...\n";
        exit(-1);
    }
    char linebuf[LINEMAX];
    
    // Get the number of games
    fgets(linebuf, LINEMAX, datap);
    int saved_gamenum = atoi(linebuf);

    // Write INCREMENTED count to temp.txt
    fprintf(tempp, "%d\n", saved_gamenum + 1);  
    
    // Copy the rest of data.txt to temp.txt
    while(fgets(linebuf, LINEMAX, datap)) {
        fprintf(tempp, "%s", linebuf);
    }
    
    fclose(datap);
    fclose(tempp);

    // Copy back from temp.txt to data.txt
    datap = fopen("../data/data.txt", "w");
    tempp = fopen("../data/temp.txt", "r");
    while(fgets(linebuf, LINEMAX, tempp)) {
        fprintf(datap, "%s", linebuf);
    }

    fclose(datap);
    fclose(tempp);
    
    return saved_gamenum;  // Returns the OLD count
}