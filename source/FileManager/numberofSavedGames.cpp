#include "innerFunctions.hpp"

int number_of_games(){
    FILE* fptr = open_data_file("data.txt", "r");
    if(fptr == NULL) return 0;
    int numofgames;
    if(fscanf(fptr, "%d", &numofgames) != 1) numofgames = 0;
    fclose(fptr);
    return numofgames;
}
