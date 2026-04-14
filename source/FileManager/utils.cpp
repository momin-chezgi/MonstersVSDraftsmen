
#include "innerFunctions.hpp"

FILE* open_data_file(const char* filename, const char* mode){
    const char* data_roots[] = {"data", "../data", "../../data"};
    char path[256];
    for(const char* root : data_roots){
        snprintf(path, sizeof(path), "%s/%s", root, filename);
        FILE* file = fopen(path, mode);
        if(file != NULL) return file;
    }
    return NULL;
}

bool read_int(FILE* fptr, int* out){
    char linebuf[LINEMAX];
    if(!fgets(linebuf, LINEMAX, fptr)) return false;
    return sscanf(linebuf, "%d", out) == 1;
}

bool read_intpairs(FILE* fptr, vector<intpair>& out){
    char linebuf[LINEMAX];
    if(!fgets(linebuf, LINEMAX, fptr)) return false;

    char* p = linebuf;
    int count = 0;
    if(sscanf(p, "%d", &count) != 1) return false;
    for(int i=0; i<count; i++){
        while(*p != '\0' && *p != '<') p++;
        if(*p != '<') return false;
        int x, y;
        if(sscanf(p, "<%d,%d>", &x, &y) != 2) return false;
        out.push_back({x,y});
        p = strchr(p, '>');
        if(p == NULL) return false;
        p++;
    }
    return true;
}

bool read_draftsmen(FILE* fptr, vector<draftsman>& out){
    char linebuf[LINEMAX];
    if(!fgets(linebuf, LINEMAX, fptr)) return false;

    char* p = linebuf;
    int count = 0;
    if(sscanf(p, "%d", &count) != 1) return false;
    for(int i=0; i<count; i++){
        while(*p != '\0' && *p != '<') p++;
        if(*p != '<') return false;
        int id, x, y, temp_token, token_limit, winned, defeated;
        if(sscanf(p, "<%d,%d,%d,%d,%d,%d,%d>",
                    &id, &x, &y, &temp_token, &token_limit, &winned, &defeated ) != 7) return false;
        out.emplace_back(draftsman{id,x,y,temp_token,token_limit,(bool)winned,(bool)defeated});
        p = strchr(p, '>');
        if(p == NULL) return false;
        p++;
    }
    return true;
}

bool skip_games(FILE* fptr, int index){
    char linebuf[LINEMAX];
    for(int i=0; i<11*index+1; i++){
        if(!fgets(linebuf, LINEMAX, fptr)) return false;
    }
    return true;
}

int update_number_of_games() {
    FILE* datap = open_data_file("data.txt", "r");
    if(datap == NULL){
        datap = open_data_file("data.txt", "w");
        if(datap == NULL){
            cerr << "Error: data.txt could not be created.\n";
            return -1;
        }
        fprintf(datap, "0\n");
        fclose(datap);
        datap = open_data_file("data.txt", "r");
    }
    FILE* tempp = open_data_file("tmp.txt", "w");
    if(datap == NULL || tempp == NULL){
        cerr << "Error: Files don't open...\n";
        if(datap != NULL) fclose(datap);
        if(tempp != NULL) fclose(tempp);
        return -1;
    }
    char linebuf[LINEMAX];
    
    // Get the number of games
    int saved_gamenum = 0;
    if(fgets(linebuf, LINEMAX, datap)) saved_gamenum = atoi(linebuf);

    // Write INCREMENTED count to temp.txt
    fprintf(tempp, "%d\n", saved_gamenum + 1);  
    
    // Copy the rest of data.txt to temp.txt
    while(fgets(linebuf, LINEMAX, datap)) {
        fprintf(tempp, "%s", linebuf);
    }
    
    fclose(datap);
    fclose(tempp);

    // Copy back from temp.txt to data.txt
    datap = open_data_file("data.txt", "w");
    tempp = open_data_file("tmp.txt", "r");
    if(datap == NULL || tempp == NULL){
        cerr << "Error: Failed to rewrite data files.\n";
        if(datap != NULL) fclose(datap);
        if(tempp != NULL) fclose(tempp);
        return -1;
    }
    while(fgets(linebuf, LINEMAX, tempp)) {
        fprintf(datap, "%s", linebuf);
    }

    fclose(datap);
    fclose(tempp);
    
    return saved_gamenum;  // Returns the OLD count
}
