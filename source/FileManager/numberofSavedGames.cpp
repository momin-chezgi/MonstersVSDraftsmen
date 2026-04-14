#include "innerFunctions.hpp"

int number_of_games(){
    FILE* fptr = fopen("../data/data.txt", "r");
    int numofgames;
    fscanf(fptr, "%d", &numofgames);
    fclose(fptr);
    return numofgames;
}